#!/usr/bin/env Rscript

options(warn = -1)

split.int <- function(line){
  res <- as.character(line) ;
  res <- strsplit(res, " ") ;
  res <- unlist(res);
  res <- c(as.numeric(res));
  res;
}

sd2 <- function(arr){
  m <- mean(arr)
  sqrt(sum((arr - m) ^ 2) / length(arr))
}

getInput <- function(){
  f <- file("stdin")
  open(f)
  line <- readLines(f,n=1)
  line <- split.int(line)
  features <<- line[1]
  houses <<- line[2]
  
  for (i in seq(along = 1:houses)) {
    line <- readLines(f,n=1)
    line <- split.int(line)
    housesPriceVector <<- c(housesPriceVector, line[length(line)])
    line <- head(line, n = -1)
    housesVector <<- rbind(housesVector, line)
  }
  
  line <- readLines(f,n=1)
  line <- as.integer(line)
  outputNumber <<- line
  for (i in seq(along = 1:outputNumber)) {
    line <- readLines(f,n=1)
    line <- split.int(line)
    outputHouses <<- rbind(outputHouses, line)
  }
  
  close(f)
}

getFakeInput <- function(){
  features <<- 2
  houses <<- 7
  housesVector <<- rbind(housesVector, c(0.18, 0.89))
  housesVector <<- rbind(housesVector, c(1.0, 0.26))
  housesVector <<- rbind(housesVector, c(0.92, 0.11))
  housesVector <<- rbind(housesVector, c(0.07, 0.37))
  housesVector <<- rbind(housesVector, c(0.85, 0.16))
  housesVector <<- rbind(housesVector, c(0.99, 0.41))
  housesVector <<- rbind(housesVector, c(0.87, 0.47))
  housesPriceVector <<- c(109.85, 155.72, 137.66, 76.17, 139.75, 162.6, 151.77)
  outputNumber <<- 4
  outputHouses <<- data.frame()
  outputHouses <<- rbind(outputHouses, c(0.49,0.18))
  outputHouses <<- rbind(outputHouses, c(0.57,0.83))
  outputHouses <<- rbind(outputHouses, c(0.56,0.64))
  outputHouses <<- rbind(outputHouses, c(0.76,0.18))
}

printOutput <- function(){
  print(features)
  print(houses)
  print(housesVector)
  print(housesPriceVector)
  print(outputNumber)
  print(outputHouses)
}

renameCol <- function(dataframe){
  for( i in seq(1:ncol(dataframe))){
    names(dataframe)[i] <- paste("col",i)
  }
  dataframe
}

roundUp <- function(value, n){
  value <- value * (10 ^ n)
  value <- ceiling(value)
  value <- value / (10 ^ n)
  value
}

houses <<- 0
features <<- 0
housesVector <<- data.frame()
housesPriceVector <<- c()
outputNumber <<- 0
outputHouses <<- data.frame()

#getInput()
getFakeInput()

outputHouses <- renameCol(outputHouses)
housesVector <- renameCol(housesVector)

mod <- lm(housesPriceVector ~ ., data = housesVector)

for(i in seq(1:nrow(outputHouses))){
  value <- predict(mod, outputHouses[i,])
  value <- roundUp(value, 2)
  write(value, stdout())
}

#printOutput()
