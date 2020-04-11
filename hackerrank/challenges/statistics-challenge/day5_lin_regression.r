m <- c(95,85,80,70,60)
s <- c(85,95,70,65,70)

r <- lm(s~m)
r <- r$coefficients

write(round(r[2] * 80 + r[1], digits = 1), stdout())
