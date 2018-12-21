import React, { Component, FC, useState } from "react";
import { Paper, TextField, Typography, Grid } from "@material-ui/core";
import logo from "./logo.svg";
import "./App.css";

const App: FC = () => {
  const [currentMasks, setCurrentMasks] = useState(0);
  const [masksToInsertOrRemove, setMasksToInsertOrRemove] = useState(0);

  return (
    <div
      style={{
        display: "flex",
        alignContent: "center",
        justifyContent: "center"
      }}
    >
      <Paper
        style={{
          padding: 16
        }}
      >
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
              value={masksToInsertOrRemove == 0 ? "" : masksToInsertOrRemove}
              onChange={e => {
                setMasksToInsertOrRemove(Number(e.target.value));
              }}
            />
          </Grid>
          <Grid item>
            {calculateKnitting(currentMasks, masksToInsertOrRemove)}
          </Grid>
        </Grid>
      </Paper>
    </div>
  );
};

const showResult = (maskStat: number[]) => {
  switch (maskStat.length) {
    case 0: {
      return <Typography variant="h4">ingen input endnu</Typography>;
    }
    case 1: {
      return (
        <Typography variant="h4">
          {`Du skal sætte 1 maske ind for hver ${maskStat[0]}`}
        </Typography>
      );
    }
    default: {
      return maskStat.map((value, index) => (
        <Typography
          key={index}
          variant="h4"
        >{`Strik ${value} sæt 1 ind`}</Typography>
      ));
    }
  }
};

const calculateKnitting = (
  currentMasks: number,
  masksToInsertOrRemove: number
) => {
  if (currentMasks === 0 || masksToInsertOrRemove === 0) {
    return showResult([]);
  }
  const temp = currentMasks / masksToInsertOrRemove;
  const floored = Math.floor(temp);
  const roofed = Math.ceil(temp);
  if (floored === roofed) {
    return showResult([temp]);
  }
  return showResult([floored, roofed]);
};

export default App;
