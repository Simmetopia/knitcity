type state = {
  currentMasks: int,
  masksToInsert: int,
};

type action =
  | SetCurrentMasks(int)
  | SetMasksToInsert(int);

let initialState = () => {currentMasks: 0, masksToInsert: 0};

let reducer = (action, state) =>
  switch (action) {
  | SetCurrentMasks(toSet) =>
    ReasonReact.Update({...state, currentMasks: toSet})
  | SetMasksToInsert(toSet) =>
    ReasonReact.Update({...state, masksToInsert: toSet})
  };

let component = ReasonReact.reducerComponent("AppRoot");

let make = _children => {
  ...component,
  reducer,
  initialState,
  render: self =>
    <div className=BackgroundWrapper.Styles.root>
      <div className=BackgroundWrapper.Styles.innerRoot>
        <Grid
          spacing=ThirtyTwo
          direction=`column
          alignContent=`center
          justify=`center>
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
                self.send(SetCurrentMasks(ReactEvent.Form.target(e)##value))
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
                  SetMasksToInsert(ReactEvent.Form.target(e)##value),
                )
              }
            />
          </Grid.Item>
        </Grid>
      </div>
    </div>,
};

[@bs.deriving abstract]
type jsProps = {children: array(ReasonReact.reactElement)};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(jsProps->childrenGet)
  );