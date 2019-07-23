[@bs.val]
external addEventListener: (string, ReactEvent.Touch.t => unit) => unit =
  "window.addEventListener";
module Styles = {
  open Css;
  let root =
    style([
      height(`percent(100.0)),
      width(`percent(100.0)),
      position(`absolute),
      backgroundImage(
        linearGradient(
          grad(0.0),
          [(px(0), `hex("A5A6C5")), (px(100), `hex("F8DFC9"))],
        ),
      ),
    ]);
};

type routes =
  | Home
  | Calc;
type state = {
  activeRoute: routes,
  startClientX: int,
};

type actions =
  | Route(routes)
  | TouchStart(int);

type direction =
  | Left
  | Right;
let component = ReasonReact.reducerComponent("BackgroundWrapper");
let x = ref(0);
let make = _children => {
  ...component,
  didMount: self => {
    let touchListen =
      ReasonReact.Router.watchUrl(url =>
        switch (url.path) {
        | ["calc"] => self.send(Route(Calc))
        | _ => self.send(Route(Home))
        }
      );
    // a little better logic here please. But this works
    addEventListener("touchstart", e => {
      let touch =
        ReactEvent.Touch.touches(e)
        ->TouchEvent.Touch.castReactTouchListToTouchArray
        ->(Array.get(0));
      let touchVal = touch##clientX;
      x := touchVal;
    });

    addEventListener("touchend", e => {
      let touch =
        ReactEvent.Touch.changedTouches(e)
        ->TouchEvent.Touch.castReactTouchListToTouchArray
        ->(Array.get(0));
      let totalWindowWidth =
        float_of_int(touch##target->Webapi.Dom.Element.clientWidth);
      let screenChange = x^ - touch##clientX;
      let minReqMovement = totalWindowWidth *. 0.25;
      let dir = screenChange > 0 ? Left : Right;
      if (abs(screenChange) > int_of_float(minReqMovement)) {
        switch (dir) {
        | Left => ReasonReact.Router.push("/calc")
        | Right => ReasonReact.Router.push("/")
        };
      };
      x := 0;
    });

    self.onUnmount(() => ReasonReact.Router.unwatchUrl(touchListen));
  },
  reducer: (action, state) => {
    switch (action) {
    | Route(toChange) =>
      ReasonReact.Update({...state, activeRoute: toChange})
    | TouchStart(startX) =>
      ReasonReact.Update({...state, startClientX: startX})
    };
  },
  initialState: () => {activeRoute: Home, startClientX: 0},
  render: self =>
    <div className=Styles.root>
      <App.Header />
      {switch (self.state.activeRoute) {
       | Home => <App />
       | Calc => <RowCalcRoot />
       }}
    </div>,
};
[@bs.deriving abstract]
type jsProps = {children: array(ReasonReact.reactElement)};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(jsProps->childrenGet)
  );
