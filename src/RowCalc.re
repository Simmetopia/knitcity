module Styles = {
  open Css;
  let floatingRightSideBack =
    style([position(absolute), top(`percent(50.0)), left(px(5))]);
  let numberWrapper =
    style([
      border(px(1), solid, rgba(0, 0, 0, 0.87)),
      borderRadius(px(5)),
      padding2(~v=px(12), ~h=px(24)),
    ]);
};

type state = {rows: int};

type actions =
  | Increment
  | Reset
  | Set(int);

let initialState = () => {rows: 0};

let reducer = (action, state) => {
  switch (action) {
  | Increment =>
    Dom.Storage.(
      localStorage |> setItem("rows", string_of_int(state.rows + 1))
    );
    ReasonReact.Update({rows: state.rows + 1});
  | Reset =>
    Dom.Storage.(localStorage |> setItem("rows", "0"));
    ReasonReact.Update({rows: 0});
  | Set(toSet) => ReasonReact.Update({rows: toSet})
  };
};

let component = ReasonReact.reducerComponent("RowCalculator");
let make = _children => {
  ...component,
  reducer,
  initialState,
  didMount: self => {
    let value = Dom.Storage.(localStorage |> getItem("rows"));
    switch (value) {
    | Some(data) => self.send(Set(int_of_string(data)))
    | None => ()
    };
  },
  render: self => {
    <>
      <div className=App.Styles.innerRoot>
        <Grid direction=`column alignItems=`center>
          <Grid.Item>
            <div className=Styles.numberWrapper>
              <Typography variant=`h6>
                {ReasonReact.string(string_of_int(self.state.rows))}
              </Typography>
            </div>
          </Grid.Item>
          /* <TextField
               variant=`outlined
               value={string_of_int(self.state.rows)}
               onChange={_e => ()}
               type_=`number
               fullWidth=true
               label={ReasonReact.string({js|Maske antal|js})}
               disabled=true
             /> */
          <Grid.Item>
            <Grid>
              <Grid.Item>
                <Button variant=`text onClick={_e => self.send(Increment)}>
                  {ReasonReact.string("+1")}
                </Button>
              </Grid.Item>
              <Grid.Item>
                <Button variant=`text onClick={_e => self.send(Reset)}>
                  {ReasonReact.string("Reset")}
                </Button>
              </Grid.Item>
            </Grid>
          </Grid.Item>
        </Grid>
      </div>
      <div
        className=Styles.floatingRightSideBack
        onClick={_e => ReasonReact.Router.push("/")}>
        <NavigationIcons.Back />
      </div>
    </>;
  },
};