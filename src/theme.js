import { amber, blue } from "@material-ui/core/colors";
import createMuiTheme from "@material-ui/core/styles/createMuiTheme";
export default createMuiTheme({
  palette: {
    secondary: amber,
    primary: blue
  },
  typography: {
    fontFamily: "Varela Round",
    useNextVariants: true
  }
});
