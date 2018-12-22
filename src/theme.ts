import { createMuiTheme } from "@material-ui/core";
import { amber, blue } from "@material-ui/core/colors";

export default createMuiTheme({
  palette: {
    secondary: amber,
    primary: blue
  },
  typography: {
    fontFamily: "Varela Round"
  }
});
