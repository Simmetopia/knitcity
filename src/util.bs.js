// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Typography$KnitZilla = require("./mat-bindings/Typography.bs.js");

function calculateMasks(currentMasks, masksToInsertOrRemove) {
  if (currentMasks !== 0) {
    if (masksToInsertOrRemove !== 0) {
      if (masksToInsertOrRemove > currentMasks) {
        return /* array */[];
      } else {
        var temp = currentMasks / masksToInsertOrRemove;
        var floored = Math.floor(temp);
        var ceiled = Math.ceil(temp);
        var diff = temp - floored;
        if (diff > 0.85) {
          return /* array */[ceiled];
        } else if (diff < 0.15) {
          return /* array */[floored];
        } else if (diff === 0) {
          return /* array */[temp];
        } else {
          return /* array */[
                  floored,
                  ceiled
                ];
        }
      }
    } else {
      return /* array */[];
    }
  } else {
    return /* array */[];
  }
}

var component = ReasonReact.statelessComponent("Result");

function make(results, _children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (_self) {
              var listLength = results.length;
              if (listLength !== 0) {
                if (listLength !== 1) {
                  return $$Array.mapi((function (index, result) {
                                return ReasonReact.element(String(index), undefined, Typography$KnitZilla.make(undefined, undefined, undefined, /* array */[" strik 1 maske ind pr " + (String(result) + " maske(r) ")]));
                              }), results);
                } else {
                  var result = Caml_array.caml_array_get(results, 0);
                  return ReasonReact.element(undefined, undefined, Typography$KnitZilla.make(undefined, undefined, undefined, /* array */[" Strik 1 maske ind pr " + (String(result) + " maske(r) ")]));
                }
              } else {
                return ReasonReact.element(undefined, undefined, Typography$KnitZilla.make(undefined, undefined, undefined, /* array */["Intet at udregne endnu"]));
              }
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

var Result = /* module */[
  /* component */component,
  /* make */make
];

exports.calculateMasks = calculateMasks;
exports.Result = Result;
/* component Not a pure module */
