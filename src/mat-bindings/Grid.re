[@bs.module "@material-ui/core/Grid/Grid"]
external grid: ReasonReact.reactClass = "default";

[@bs.deriving jsConverter]
type alignContent = [
  | `stretch
  | `center
  | [@bs.as "flex-start"] `flexStart
  | [@bs.as "flex-end"] `flexEnd
  | [@bs.as "space-between"] `spaceBetween
  | [@bs.as "space-around"] `spaceAround
];

[@bs.deriving jsConverter]
type alignItems = [
  | [@bs.as "flex-start"] `flexStart
  | `center
  | [@bs.as "flex-end"] `flexEnd
  | `stretch
  | `baseline
];

[@bs.deriving jsConverter]
type direction = [
  | `row
  | [@bs.as "row-reverse"] `rowReverse
  | `column
  | [@bs.as "column-reverse"] `columnReverse
];

[@bs.deriving jsConverter]
type justify = [
  | [@bs.as "flex-start"] `flexStart
  | `center
  | [@bs.as "flex-end"] `flexEnd
  | [@bs.as "space-between"] `spaceBetween
  | [@bs.as "space-around"] `spaceAround
  | [@bs.as "space-evenly"] `spaceEvenly
];

[@bs.deriving jsConverter]
type spacing =
  | Zero
  | [@bs.as 1] One
  | [@bs.as 2] Two
  | [@bs.as 3] Three;

[@bs.deriving abstract]
type jsProps = {
  alignContent: string,
  alignItems: string,
  direction: string,
  justify: string,
  spacing: int,
  container: bool,
};

let make =
    (
      ~alignContent=`flexStart,
      ~alignItems=`flexStart,
      ~direction=`row,
      ~justify=`flexStart,
      ~spacing=Zero,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=grid,
    ~props=
      jsProps(
        ~container=true,
        ~alignContent=alignContent |> alignContentToJs,
        ~alignItems=alignItems |> alignItemsToJs,
        ~direction=direction |> directionToJs,
        ~justify=justify |> justifyToJs,
        ~spacing=spacing |> spacingToJs,
      ),
    children,
  );

module Item = {
  [@bs.deriving abstract]
  type jsProps = {
    ml: Js.nullable(int),
    item: bool,
  };
  let make = (~ml=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=grid,
      ~props=jsProps(~ml=ml |> Js.Nullable.fromOption, ~item=true),
      children,
    );
};
