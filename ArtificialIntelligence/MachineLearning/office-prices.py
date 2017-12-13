from sklearn.model_selection import train_test_split
from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import Ridge
from sklearn.pipeline import make_pipeline
import numpy as np
a = list(map(int, input().strip().split(' ')))
F = a[0]
N = a[1]
dataset = []

for i in range(N):
    arr = list(map(float, input().strip().split(' ')))
    dataset.append(arr)

dataset = np.array(dataset)

X = dataset[:, :F]
y = dataset[:, F:]


linreg = make_pipeline(PolynomialFeatures(degree=2), Ridge())
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25)

linreg.fit(X_train, y_train)

T = int(input())
test_case = []
for ij in range(T):
    arr = list(map(float, input().strip().split(' ')))
    test_case.append(arr)

test_case = np.array(test_case)

for data in test_case:
    print(linreg.predict([data])[0][0])
