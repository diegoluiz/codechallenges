#3x+4y+8=0
#4x+3y+7=0

fx <- function (x){
  r <- (3 * x + 8) / -4
}

fy <- function (y){
  r <- (3 * y + 7) / -4  
}

getSlope <- function(a,f){
  b <- f(a)
  print(a[2] - a[1])
  print(b[2] - b[1])
}

max <- 100
s <- 1:max
x <- seq(s)
y <- seq(s)

a <- c(20,60)
b <- fx(a)

getSlope(a, fx)
getSlope(a, fy)

l1 <- 1:100
l2 <- fx(l1)

# plot nice chart
x <- x + rnorm(max, mean = 0, sd = 2) 
rx <- fx(x)
plot(rx)
#ry <- fy(y)
#plot(ry)
#lines(fx(1:max))
abline(h = fx(a), v = a, col = "black", lty = 3)
