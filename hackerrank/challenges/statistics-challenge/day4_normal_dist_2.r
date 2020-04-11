m <- 20
sd <- 2

p1 <- 19.5
p3a <- 20
p3b <- 22

write(trunc(pnorm(p1, mean = m, sd = sd, lower.tail = TRUE) * 1000) / 1000, stdout())
write(trunc((1 - pnorm(p3a, mean = m, sd = sd, lower.tail = TRUE) - pnorm(p3b, mean = m, sd = sd, lower.tail = FALSE)) * 1000) / 1000, stdout())
