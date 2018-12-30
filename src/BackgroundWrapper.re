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
          [(0, `hex("A5A6C5")), (100, `hex("F8DFC9"))],
        ),
      ),
    ]);
  let innerRoot =
    style([
      padding(px(16)),
      position(absolute),
      top(`percent(50.0)),
      left(`percent(50.0)),
      transform(translate(`percent(-50.0), `percent(-50.0))),
    ]);
};