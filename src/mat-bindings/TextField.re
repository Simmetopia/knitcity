[@bs.module "@material-ui/core/TextField/TextField"]
external textField: ReasonReact.reactClass = "default";

[@bs.deriving abstract]
type jsProps = {
  variant: string,
  [@bs.as "type"]
  type_: string,
  value: string,
  label: ReasonReact.reactElement,
  fullWidth: bool,
  onChange: ReactEvent.Form.t => unit,
  disabled: Js.nullable(bool),
};

[@bs.deriving jsConverter]
type variant = [ | `standard | `outlined | `filled];

[@bs.deriving jsConverter]
type type_ = [ | `number | `email | `text];

let make =
    (
      ~value,
      ~fullWidth,
      ~onChange,
      ~label,
      ~type_,
      ~variant=`standard,
      ~disabled=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=textField,
    ~props=
      jsProps(
        ~variant=variant |> variantToJs,
        ~value,
        ~fullWidth,
        ~label,
        ~type_=type_ |> type_ToJs,
        ~disabled=disabled |> Js.Nullable.fromOption,
        ~onChange,
      ),
    children,
  );