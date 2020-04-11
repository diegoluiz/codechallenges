tot <- 9800
cbox <- 49
mbox <- 205
sdbox <- 15
lbox <- tot / cbox

sd <- sdbox / sqrt(cbox)

write(trunc(pnorm(lbox, mean = mbox, sd = sd, lower.tail = TRUE) * 10000) / 10000, stdout())

