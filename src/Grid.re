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

[@bs.deriving abstract]
type jsProps = {
  alignContent: Js.nullable(string),
  alignItems: string,
  direction: string,
  justify: string,
  container: Js.nullable(bool),
  item: Js.nullable(bool),
};

let make =
    (
      ~container=?,
      ~alignContent:option(alignContent)=?,
      ~alignItems=?,
      ~direction=?,
      ~justify=?,
      ~item=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=grid,
    ~props=
      jsProps(
        ~container=container |> Js.Nullable.fromOption,
        ~alignContent= Some(alignContentToJs(Js.Option.getExn(alignContent))) |> Js.Nullable.fromOption ,
        ~alignItems=alignItems |> alignItemsToJs,
        ~direction=direction |> directionToJs,
        ~justify=justify |> justifyToJs,
        ~item=item |> Js.Nullable.fromOption,
      ),
    children,
  );
