tot <- 250
cbox <- 100
mbox <- 2.4
sdbox <- 2
lbox <- tot / cbox

sd <- sdbox / sqrt(cbox)

write(trunc(pnorm(lbox, mean = mbox, sd = sd, lower.tail = TRUE) * 10000) / 10000, stdout())
