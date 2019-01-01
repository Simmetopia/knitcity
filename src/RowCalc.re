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
    <Grid direction=`column alignItems=`center>
      <Grid.Item>
        <Typography variant=`h6>
          {ReasonReact.string(string_of_int(self.state.rows))}
        </Typography>
      </Grid.Item>
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
    </Grid>;
  },
};