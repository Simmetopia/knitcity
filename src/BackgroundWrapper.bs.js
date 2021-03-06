// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Css = require("bs-css/src/Css.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var Pervasives = require("bs-platform/lib/js/pervasives.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var App$KnitZilla = require("./App.bs.js");
var ReasonReactRouter = require("reason-react/src/ReasonReactRouter.js");
var RowCalcRoot$KnitZilla = require("./RowCalcRoot.bs.js");

var root = Css.style(/* :: */[
      Css.height(/* `percent */[
            -119887163,
            100.0
          ]),
      /* :: */[
        Css.width(/* `percent */[
              -119887163,
              100.0
            ]),
        /* :: */[
          Css.position(/* absolute */-1013592457),
          /* :: */[
            Css.backgroundImage(Css.linearGradient(Css.grad(0.0), /* :: */[
                      /* tuple */[
                        Css.px(0),
                        /* `hex */[
                          5194459,
                          "A5A6C5"
                        ]
                      ],
                      /* :: */[
                        /* tuple */[
                          Css.px(100),
                          /* `hex */[
                            5194459,
                            "F8DFC9"
                          ]
                        ],
                        /* [] */0
                      ]
                    ])),
            /* [] */0
          ]
        ]
      ]
    ]);

var Styles = /* module */[/* root */root];

var component = ReasonReact.reducerComponent("BackgroundWrapper");

var x = /* record */[/* contents */0];

function make(_children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */(function (self) {
              var touchListen = ReasonReactRouter.watchUrl((function (url) {
                      var match = url[/* path */0];
                      if (match && match[0] === "calc" && !match[1]) {
                        return Curry._1(self[/* send */3], /* Route */Block.__(0, [/* Calc */1]));
                      } else {
                        return Curry._1(self[/* send */3], /* Route */Block.__(0, [/* Home */0]));
                      }
                    }));
              window.addEventListener("touchstart", (function (e) {
                      var touch = Caml_array.caml_array_get(e.touches, 0);
                      var touchVal = touch.clientX;
                      x[0] = touchVal;
                      return /* () */0;
                    }));
              window.addEventListener("touchend", (function (e) {
                      var touch = Caml_array.caml_array_get(e.changedTouches, 0);
                      var totalWindowWidth = touch.target.clientWidth;
                      var screenChange = x[0] - touch.clientX | 0;
                      var minReqMovement = totalWindowWidth * 0.25;
                      var match = screenChange > 0;
                      var dir = match ? /* Left */0 : /* Right */1;
                      if (Pervasives.abs(screenChange) > (minReqMovement | 0)) {
                        if (dir) {
                          ReasonReactRouter.push("/");
                        } else {
                          ReasonReactRouter.push("/calc");
                        }
                      }
                      x[0] = 0;
                      return /* () */0;
                    }));
              return Curry._1(self[/* onUnmount */4], (function (param) {
                            return ReasonReactRouter.unwatchUrl(touchListen);
                          }));
            }),
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (self) {
              var match = self[/* state */1][/* activeRoute */0];
              return React.createElement("div", {
                          className: root
                        }, ReasonReact.element(undefined, undefined, App$KnitZilla.Header[/* make */2](/* array */[])), match ? ReasonReact.element(undefined, undefined, RowCalcRoot$KnitZilla.make(/* array */[])) : ReasonReact.element(undefined, undefined, App$KnitZilla.make(/* array */[])));
            }),
          /* initialState */(function (param) {
              return /* record */[
                      /* activeRoute : Home */0,
                      /* startClientX */0
                    ];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (action.tag) {
                return /* Update */Block.__(0, [/* record */[
                            /* activeRoute */state[/* activeRoute */0],
                            /* startClientX */action[0]
                          ]]);
              } else {
                return /* Update */Block.__(0, [/* record */[
                            /* activeRoute */action[0],
                            /* startClientX */state[/* startClientX */1]
                          ]]);
              }
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

var $$default = ReasonReact.wrapReasonForJs(component, (function (jsProps) {
        return make(jsProps.children);
      }));

exports.Styles = Styles;
exports.component = component;
exports.x = x;
exports.make = make;
exports.$$default = $$default;
exports.default = $$default;
exports.__esModule = true;
/* root Not a pure module */
