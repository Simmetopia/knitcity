module Header = {
  module Style = {
    open Css;
    let headerStyle =
      style([
        position(absolute),
        top(px(25)),
        width(`percent(100.0)),
        color(hsl(28, 100, 94)),
      ]);
  };
  let component = ReasonReact.statelessComponent("Header");
  let make = _children => {
    ...component,
    render: _self => {
      <Typography className=Style.headerStyle variant=`h3>
        {ReasonReact.string("KnitZilla")}
      </Typography>;
    },
  };
};
module Styles = {
  open Css;
  let innerRoot =
    style([
      padding(px(16)),
      position(absolute),
      top(`percent(50.0)),
      left(`percent(50.0)),
      transform(translate(`percent(-50.0), `percent(-50.0))),
    ]);
};

type state = {
  currentMasks: int,
  masksToInsert: int,
};

type action =
  | SetCurrentMasks(int)
  | SetMasksToInsert(int);

let component = ReasonReact.reducerComponent("AppRoot");

let nanTest = toTest => {
  let nanTest = compare(float_of_int(toTest), nan);

  switch (nanTest) {
  | 0 => 0
  | _ => toTest
  };
};

let make = _children => {
  ...component,
  reducer: (action, state) =>
    switch (action) {
    | SetCurrentMasks(toSet) =>
      ReasonReact.Update({...state, currentMasks: nanTest(toSet)})
    | SetMasksToInsert(toSet) =>
      ReasonReact.Update({...state, masksToInsert: nanTest(toSet)})
    },
  initialState: () => {currentMasks: 0, masksToInsert: 0},
  render: self => {
    <>
      <Header />
      <div className=Styles.innerRoot>
        <Grid
          spacing=Sixteen direction=`column alignItems=`center justify=`center>
          <Grid.Item>
            <TextField
              variant=`outlined
              label={ReasonReact.string("Antal masker")}
              fullWidth=true
              value={
                self.state.currentMasks === 0 ?
                  "" : string_of_int(self.state.currentMasks)
              }
              type_=`number
              onChange={e =>
                self.send(
                  SetCurrentMasks(ReactEvent.Form.target(e)##valueAsNumber),
                )
              }
            />
          </Grid.Item>
          <Grid.Item>
            <TextField
              variant=`outlined
              label={ReasonReact.string({js|Indsæt|js})}
              type_=`number
              fullWidth=true
              value={
                self.state.masksToInsert === 0 ?
                  "" : string_of_int(self.state.masksToInsert)
              }
              onChange={e =>
                self.send(
                  SetMasksToInsert(ReactEvent.Form.target(e)##valueAsNumber),
                )
              }
            />
          </Grid.Item>
          <Grid.Item>
            <Util.Result
              results={Util.calculateMasks(
                ~currentMasks=self.state.currentMasks,
                ~masksToInsertOrRemove=self.state.masksToInsert,
              )}
            />
          </Grid.Item>
        </Grid>
      </div>
      <Button
        color=`primary
        variant=`contained
        onClick={_e => ReasonReact.Router.push("/calc")}>
        {ReasonReact.string("Rower")}
      </Button>
    </>;
  },
};