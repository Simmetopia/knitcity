import React from "react";
import Typography from "@material-ui/core/Typography/Typography";
import { createStyles, withStyles } from "@material-ui/core";
const typographyWrapper = ({ children, classes: { textStyle } }) => {
  return (
    <Typography className={textStyle} align="center" variant="h6">
      {children}
    </Typography>
  );
};
const TypographyWrapperStyles = createStyles({
  textStyle: {
    color: "hsl(200,25%,25%)"
  }
});
export default withStyles(TypographyWrapperStyles)(typographyWrapper);
