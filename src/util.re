let default = (~currentMasks, ~masksToInsertOrRemove) => {
  switch (currentMasks, masksToInsertOrRemove) {
  | (0, _) => [||]
  | (_, 0) => [||]
  | (_, _) =>
    let temp =
      float_of_int(currentMasks) /. float_of_int(masksToInsertOrRemove);
    let floored = floor(temp);
    let ceiled = ceil(temp);
    let diff = temp -. floored;
    switch (diff) {
    | _ when diff > 0.85 => [|ceiled|]
    | _ when diff < 0.15 => [|floored|]
    | _ when diff == 0. => [|temp|]
    | _ => [|floored, ceiled|]
    };
  };
};

module TypographyWrapper = {
  [@bs.module "./TypographyWrapper"]
  external typographyWrapper: ReasonReact.reactClass = "default";
  [@bs.obj] external makeProps: unit => _ = "";
  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass=typographyWrapper,
      ~props=makeProps(),
      children,
    );
};

module Result = {
  let component = ReasonReact.statelessComponent("Result");

  let make = (~results: array(int), _children) => {
    ...component,
    render: _self => {
      let listLength = Array.length(results);
      switch (listLength) {
      | 0 =>
        <TypographyWrapper>
          {ReasonReact.string("Intet at udregne endnu")}
        </TypographyWrapper>
      | 1 =>
        let result = results[0];
        <TypographyWrapper>
          {ReasonReact.string({j| Strik 1 maske ind pr $result maske(r) |j})}
        </TypographyWrapper>;
      | _ =>
        results
        |> Array.map(result =>
             <TypographyWrapper key={string_of_int(result)}>
               {ReasonReact.string(
                  {j| strik 1 maske ind pr $result maske(r) |j},
                )}
             </TypographyWrapper>
           )
        |> ReasonReact.array
      };
    },
  };
};
[@bs.deriving abstract]
type jsProps = {results: array(int)};
let resultJs =
  ReasonReact.wrapReasonForJs(~component=Result.component, jsProps =>
    Result.make(~results=jsProps->resultsGet, [||])
  );
