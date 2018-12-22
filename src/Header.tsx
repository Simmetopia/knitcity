import { Theme } from "@material-ui/core/styles/createMuiTheme";
import createStyles from "@material-ui/core/styles/createStyles";
import withStyles, { WithStyles } from "@material-ui/core/styles/withStyles";
import Typography from "@material-ui/core/Typography/Typography";
import React, { FC } from "react";

export const header: FC<WithStyles<typeof styles>> = ({ classes }) => {
  const { root } = classes;
  return (
    <Typography align="center" variant="h3" className={root}>
      KnitZilla
    </Typography>
  );
};

const styles = (theme: Theme) =>
  createStyles({
    root: {
      position: "absolute",
      top: "25px",
      width: "100%",
      color: "hsl(206,100%,94%)"
    }
  });

export default withStyles(styles)(header);
