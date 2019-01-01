[@bs.module "@material-ui/core/Typography/Typography"]
external typography: ReasonReact.reactClass = "default";

[@bs.deriving jsConverter]
type align = [ | `center];

[@bs.deriving jsConverter]
type variant = [ | `h3 | `body1 | `h6];

[@bs.deriving abstract]
type jsProps = {
  variant: string,
  align: string,
  className: Js.nullable(string),
};

let make = (~variant=`body1, ~align=`center, ~className=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=typography,
    ~props=
      jsProps(
        ~className=className |> Js.Nullable.fromOption,
        ~variant=variant |> variantToJs,
        ~align=align |> alignToJs,
      ),
    children,
  );