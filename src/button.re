[@bs.module "@material-ui/core/Button/Button"]
external button: ReasonReact.reactClass = "default";
type onClick = ReactEvent.Mouse.t => unit;
[@bs.obj]
external makeProps: (~variant: string=?, ~onClick: onClick, unit) => _ = "";
[@bs.deriving jsConverter]
type variant = [ | `text | `outlined | `contained | `fab | `extendedFab];

let make = (~variant=?, ~onClick, children) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=button,
    ~props=
      makeProps(
        ~variant=?variant |> Js.Option.map((. a) => variantToJs(a)),
        ~onClick,
        (),
      ),
    children,
  );
};
