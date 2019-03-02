module RowCalcParser = {
  type rowCalc = {
    title: string,
    rows: int,
  };
  type rows = array(rowCalc);
  let decodeRow = jsonString => {
    Json.Decode.{
      title: jsonString |> field("title", string),
      rows: jsonString |> field("rows", int),
    };
  };
  let decode = jsonString => Json.Decode.(jsonString |> array(decodeRow));

  let encodeRow = row => {
    Json.Encode.(
      object_([("title", string(row.title)), ("rows", int(row.rows))])
    );
  };
  let encode = (rows: array(rowCalc)) => {
    Json.Encode.(rows |> array(encodeRow));
  };
};
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
  let formControl =
    style([
      position(absolute),
      bottom(`percent(5.0)),
      right(`percent(50.0)),
      transform(translateX(`percent(50.0))),
    ]);
  let counterContainer =
    style([
      width(`percent(80.0)),
      overflowY(auto),
      height(`percent(60.0)),
    ]);
};
type state = {
  rows: RowCalcParser.rows,
  titleVal: string,
};
type actions =
  | AddNewRow
  | RemoveRow
  | Reset
  | UpdateRowIncrement(int)
  | ChangeText(string)
  | UpdateRowReset(int);

let component = ReasonReact.reducerComponent("RowCalcRoot");

let make = _children => {
  ...component,
  initialState: () => {
    let jsonStringOpt = Dom.Storage.(localStorage |> getItem("rowCalcs"));

    let rows =
      switch (jsonStringOpt) {
      | Some(jsonString) =>
        switch (jsonString |> Json.parse) {
        | Some(json) => RowCalcParser.decode(json)
        | None => [||]
        }

      | None => [||]
      };
    {rows, titleVal: ""};
  },
  reducer: (action, state) => {
    switch (action) {
    | AddNewRow =>
      let newRows: RowCalcParser.rows = [|{title: state.titleVal, rows: 0}|];
      ReasonReact.Update({
        rows: Array.concat([state.rows, newRows]),
        titleVal: "",
      });
    | RemoveRow => ReasonReact.Update(state)
    | Reset => ReasonReact.Update({...state, rows: [||]})
    | UpdateRowIncrement(index) =>
      let newState = state;
      let toUpdate = newState.rows[index];
      newState.rows[index] = {title: toUpdate.title, rows: toUpdate.rows + 1};
      ReasonReact.Update(newState);
    | UpdateRowReset(index) =>
      let newState = state;
      let toUpdate = newState.rows[index];
      newState.rows[index] = {title: toUpdate.title, rows: 0};
      ReasonReact.Update(newState);
    | ChangeText(toChange) =>
      ReasonReact.Update({...state, titleVal: toChange})
    };
  },
  didUpdate: ({newSelf}) => {
    Js.log(newSelf.state.rows);
    Dom.Storage.(
      localStorage
      |> setItem(
           "rowCalcs",
           newSelf.state.rows |> RowCalcParser.encode |> Json.stringify,
         )
    );
  },
  render: self => {
    <>
      <div className={App.Styles.innerRoot ++ " " ++ Styles.counterContainer}>
        <Grid justify=`center>
          {self.state.rows
           |> Array.mapi((index, a: RowCalcParser.rowCalc) =>
                <Grid.Item key={string_of_int(index)}>
                  <RowCalc
                    rows={a.rows}
                    title={a.title}
                    index
                    newValues={action =>
                      switch (action) {
                      | Count(index) => self.send(UpdateRowIncrement(index))
                      | Reset(index) => self.send(UpdateRowReset(index))
                      }
                    }
                  />
                </Grid.Item>
              )
           |> ReasonReact.array}
        </Grid>
      </div>
      <div className=Styles.formControl>
        <Button onClick={_e => self.send(AddNewRow)}>
          {ReasonReact.string("+ counter")}
        </Button>
        <Button onClick={_e => self.send(Reset)}>
          {ReasonReact.string("Reset")}
        </Button>
        <TextField
          value={self.state.titleVal}
          type_=`text
          fullWidth=false
          label={ReasonReact.string("Name")}
          onChange={e =>
            self.send(ChangeText(ReactEvent.Form.target(e)##value))
          }
        />
      </div>
      <div
        className=Styles.floatingRightSideBack
        onClick={_e => ReasonReact.Router.push("/")}>
        <NavigationIcons.Back />
      </div>
    </>;
  },
};