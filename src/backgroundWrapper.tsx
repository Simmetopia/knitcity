import React, { FC } from "react";
import { amber, blue } from "@material-ui/core/colors";
import withStyles, { WithStyles } from "@material-ui/core/styles/withStyles";
import { Theme } from "@material-ui/core/styles/createMuiTheme";
import createStyles from "@material-ui/core/styles/createStyles";

const BackgroundWrapper: FC<WithStyles<typeof styles>> = ({
  children,
  classes: { root }
}) => <div className={root}>{children}</div>;

const styles = (theme: Theme) =>
  createStyles({
    root: {
      height: "100%",
      width: "100%",
      position: "absolute",
      backgroundImage: `linear-gradient(${blue[300]},${amber[50]})`
    }
  });

export default withStyles(styles)(BackgroundWrapper);
