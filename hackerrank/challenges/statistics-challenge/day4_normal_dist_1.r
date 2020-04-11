m <- 30
sd <- 4

p1 <- 40
p2 <- 21
p3a <- 30
p3b <- 35

write(trunc(pnorm(p1, mean = m, sd = sd, lower.tail = TRUE) * 1000) / 1000, stdout())
write(trunc(pnorm(p2, mean = m, sd = sd, lower.tail = FALSE) * 1000) / 1000, stdout())
write(trunc((1 - pnorm(p3a, mean = m, sd = sd, lower.tail = TRUE) - pnorm(p3b, mean = m, sd = sd, lower.tail = FALSE)) * 1000) / 1000, stdout())
