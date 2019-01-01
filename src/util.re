let calculateMasks = (~currentMasks, ~masksToInsertOrRemove) => {
  switch (currentMasks, masksToInsertOrRemove) {
  | (0, _) => [||]
  | (_, 0) => [||]
  | (_, _) when masksToInsertOrRemove > currentMasks => [||]
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

module Result = {
  let component = ReasonReact.statelessComponent("Result");

  let make = (~results, _children) => {
    ...component,
    render: _self => {
      let listLength = Array.length(results);
      switch (listLength) {
      | 0 =>
        <Typography>
          {ReasonReact.string("Intet at udregne endnu")}
        </Typography>
      | 1 =>
        let result = results[0];
        <Typography>
          {ReasonReact.string({j| Strik 1 maske ind pr $result maske(r) |j})}
        </Typography>;
      | _ =>
        results
        |> Array.mapi((index, result) =>
             <Typography key={string_of_int(index)}>
               {ReasonReact.string(
                  {j| strik 1 maske ind pr $result maske(r) |j},
                )}
             </Typography>
           )
        |> ReasonReact.array
      };
    },
  };
};