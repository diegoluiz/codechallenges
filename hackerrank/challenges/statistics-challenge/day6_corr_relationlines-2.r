
# There are 22 series of data involving index numbers: P for price index and S for the commodity stock. 
# The mean and standard deviation of P are 100 and 8, respectively.
# The mean and standard deviation of S are 103 and 4, respectively. 
# The R2R2 correlation coefficient between the two series is 0.4.

# ß = r[sy/sx] 
# α = y bar - ß (x bar) 
# where y bar is the mean of the y data 
# ß is the previously computed slope of the regression line 
# and x bar is the mean of the x data

pM <- 100
pSd <- 8
sM <- 103
sSd <- 4
corr <- 0.4

b <- sqrt(corr) * (pSd/sSd)
b
sqrt(b)

#a <- pM - b * sM
#a


#b <- corr * (sSd/pSd)
#a <- sM - b * pM
#a