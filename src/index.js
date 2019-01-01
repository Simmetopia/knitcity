import React from "react";
import ReactDOM from "react-dom";
import App from "./BackgroundWrapper.bs";
import * as serviceWorker from "./serviceWorker";
import MuiThemeProvider from "@material-ui/core/styles/MuiThemeProvider";
import theme from "./theme";
import CssBaseline from "@material-ui/core/CssBaseline/CssBaseline";
ReactDOM.render(
  <MuiThemeProvider theme={theme}>
    <CssBaseline />
    <App />
  </MuiThemeProvider>,
  document.getElementById("root")
);
// If you want your app to work offline and load faster, you can change
// unregister() to register() below. Note this comes with some pitfalls.
// Learn more about service workers: http://bit.ly/CRA-PWA
serviceWorker.register();
