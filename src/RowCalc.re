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
type updateActions =
  | Count(int)
  | Reset(int);
let component = ReasonReact.statelessComponent("RowCalculator");
let make =
    (~rows, ~title, ~newValues: updateActions => unit, ~index, _children) => {
  ...component,

  render: _self => {
    <>
      <Typography> {ReasonReact.string(title)} </Typography>
      <Grid direction=`column alignItems=`center>
        <Grid.Item>
          <div className=Styles.numberWrapper>
            <Typography variant=`h6>
              {ReasonReact.string(string_of_int(rows))}
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
              <Button variant=`text onClick={_e => newValues(Count(index))}>
                {ReasonReact.string("+1")}
              </Button>
            </Grid.Item>
            <Grid.Item>
              <Button variant=`text onClick={_e => newValues(Reset(index))}>
                {ReasonReact.string("Reset")}
              </Button>
            </Grid.Item>
          </Grid>
        </Grid.Item>
      </Grid>
    </>;
  },
};