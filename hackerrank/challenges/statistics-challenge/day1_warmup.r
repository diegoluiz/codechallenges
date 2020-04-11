#!/usr/bin/env Rscript

options(warn = -1)

getmode <- function(v) {
    v <- sort(v)
    uniqv <- unique(v)
    uniqv[which.max(tabulate(match(v, uniqv)))]
}

getinput <- function() {
    f <- file("stdin")
    open(f)
    line1 <- readLines(f,n=1) 
    line2 <- readLines(f,n=1) 
    close(f)
    line2
}

sd2 <- function(arr){
  m <- mean(arr)
  sqrt(sum((arr - m) ^ 2) / length(arr))
}

fakeinput <- function() {
  c(64630, 11735, 14216, 99233, 14470, 4978, 73429, 38120, 51135, 67060)
}

line <- getinput()

res <- as.character(line) ;
res <- strsplit(res, " ") ;
res <- unlist(res) ;
res <- as.vector(as.numeric(res)) ;

write(mean(res), stdout())
write(median(res), stdout())
write(getmode(res), stdout())
write(round(sd2(res), digits = 1), stdout())


