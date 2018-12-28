import createStyles from "@material-ui/core/styles/createStyles";
import withStyles from "@material-ui/core/styles/withStyles";
import Typography from "@material-ui/core/Typography/Typography";
import React from "react";
export const header = ({ classes }) => {
    const { root } = classes;
    return (<Typography align="center" variant="h3" className={root}>
      KnitZilla
    </Typography>);
};
const styles = (theme) => createStyles({
    root: {
        position: "absolute",
        top: "25px",
        width: "100%",
        color: "hsl(206,100%,94%)"
    }
});
export default withStyles(styles)(header);
