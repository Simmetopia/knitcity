import { Grid, TextField, withStyles, createStyles } from "@material-ui/core";
import React, { useState } from "react";
import BackgroundWrapper from "./backgroundWrapper";
import Header from "./Header";
import calculateKnit, { resultJs as Results } from "./util.bs";
import CounterRow from "./RowCalc.bs";
const App = ({ classes }) => {
  const [currentMasks, setCurrentMasks] = useState(0);
  const [masksToInsertOrRemove, setMasksToInsertOrRemove] = useState(0);
  const { paperRoot } = classes;
  return (
    <BackgroundWrapper>
      <Header />
      <div className={paperRoot}>
        <Grid
          container
          spacing={8}
          direction={"column"}
          alignContent="center"
          justify="center"
        >
          <Grid item>
            <TextField
              variant="outlined"
              label="Antal masker"
              fullWidth
              value={currentMasks === 0 ? "" : currentMasks}
              type="number"
              onChange={e => {
                setCurrentMasks(Number(e.target.value));
              }}
            />
          </Grid>
          <Grid item>
            <TextField
              variant="outlined"
              label="Indsæt"
              type="number"
              fullWidth
              value={masksToInsertOrRemove === 0 ? "" : masksToInsertOrRemove}
              onChange={e => {
                setMasksToInsertOrRemove(Number(e.target.value));
              }}
            />
          </Grid>
          <Grid item>
            <Results
              results={calculateKnit(currentMasks, masksToInsertOrRemove)}
            />
          </Grid>
          <Grid item>
            <CounterRow />
          </Grid>
        </Grid>
      </div>
    </BackgroundWrapper>
  );
};
const styles = theme =>
  createStyles({
    paperRoot: {
      padding: 16,
      position: "absolute",
      top: "50%",
      left: "50%",
      transform: "translate(-50%,-50%)"
      // backgroundColor: theme.palette.primary.light
    }
  });
export default withStyles(styles)(App);
