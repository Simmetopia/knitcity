import React, { FC } from "react";
import Typography from "@material-ui/core/Typography/Typography";
import { createStyles, withStyles, WithStyles } from "@material-ui/core";

export const showResult = (maskStat: number[]) => {
  switch (maskStat.length) {
    case 0: {
      return <TypographyWrapper>ingen input endnu</TypographyWrapper>;
    }
    case 1: {
      return (
        <TypographyWrapper>
          {`Du skal sætte 1 maske ind for hver ${maskStat[0]}`}
        </TypographyWrapper>
      );
    }
    default: {
      return maskStat.map((value, index) => (
        <TypographyWrapper
          key={index}
        >{`Strik ${value} sæt 1 ind`}</TypographyWrapper>
      ));
    }
  }
};

const typographyWrapper: FC<WithStyles<typeof TypographyWrapperStyles>> = ({
  children,
  classes: { textStyle }
}) => {
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

const TypographyWrapper = withStyles(TypographyWrapperStyles)(
  typographyWrapper
);

export const calculateKnitting = (
  currentMasks: number,
  masksToInsertOrRemove: number
) => {
  if (currentMasks === 0 || masksToInsertOrRemove === 0) {
    return showResult([]);
  }
  const temp = currentMasks / masksToInsertOrRemove;
  const floored = Math.floor(temp);
  const roofed = Math.ceil(temp);

  const float = temp - floored;
  if (float > 0.85) {
    return showResult([roofed]);
  }
  if (float < 0.15) {
    return showResult([floored]);
  }

  if (floored === roofed) {
    return showResult([temp]);
  }
  return showResult([floored, roofed]);
};
