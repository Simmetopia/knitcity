module InnerReason = {
  type state = {rows: int};

  type actions =
    | Increment
    | Reset;

  let initialState = () => {rows: 0};

  let reducer = (action, state) => {
    switch (action) {
    | Increment => ReasonReact.Update({rows: state.rows + 1})
    | Reset => ReasonReact.Update({rows: 0})
    };
  };

  let component = ReasonReact.reducerComponent("RowCalculator");
  let make = _children => {
    ...component,
    reducer,
    initialState,
    render: self => {
      <div>
        <Util.TypographyWrapper>
          {ReasonReact.string(string_of_int(self.state.rows))}
        </Util.TypographyWrapper>
        <Button variant=`text onClick={_e => self.send(Increment)}>
          {ReasonReact.string("+1")}
        </Button>
        <Button variant=`text onClick={_e => self.send(Reset)}>
          {ReasonReact.string("Reset")}
        </Button>
      </div>;
    },
  };
};

let component = ReasonReact.statelessComponent("wrapper");
let make = _children => {...component, render: _self => <InnerReason />};

/* The following exposes a `jsComponent` that the ReactJS side can use as
   require('greetingRe.js').jsComponent */
[@bs.deriving abstract]
type jsProps = {children: array(ReasonReact.reactElement)};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(jsProps->childrenGet)
  );
