import React from "react";
import { amber, blue } from "@material-ui/core/colors";
import withStyles from "@material-ui/core/styles/withStyles";
import createStyles from "@material-ui/core/styles/createStyles";
const BackgroundWrapper = ({ children, classes: { root } }) => (
  <div className={root}>{children}</div>
);
const styles = theme =>
  createStyles({
    root: {
      height: "100%",
      width: "100%",
      position: "absolute",
      backgroundImage: `linear-gradient(${blue[300]},${amber[50]})`
    }
  });
export default withStyles(styles)(BackgroundWrapper);
