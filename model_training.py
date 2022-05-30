

import os
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
from embedded_window import Window
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import plot_confusion_matrix, accuracy_score
from micromlgen import port


def read_csv(filename):
    return pd.read_csv(filename, index_col='t')


if __name__ == '__main__':

    path = "./extracts"
    files = [path+"/" + x for x in os.listdir(path)]
    files = [x for x in files if "chest" in x]


    ## Push up
    files_pushup = [x for x in files if "pushup" in x]
    df_pushups = pd.concat([read_csv(x) for x in files_pushup], ignore_index=True).to_numpy()

    ## Not working out
    files_rest = [x for x in files if "rest" in x]
    df_rest = pd.concat([read_csv(x) for x in files_rest], ignore_index=True).to_numpy()

    ## Squat
    files_squat = [x for x in files if "squat" in x]
    df_squat = pd.concat([read_csv(x) for x in files_squat], ignore_index=True).to_numpy()

    ## Lunges
    files_lunge = [x for x in files if "lunge" in x]
    df_lunge = pd.concat([read_csv(x) for x in files_lunge], ignore_index=True).to_numpy()

    ## abs
    files_abs = [x for x in files if "abs" in x]
    df_abs = pd.concat([read_csv(x) for x in files_abs], ignore_index=True).to_numpy()


    df_list = [
            df_pushups,
            df_squat,
            df_abs,
            df_lunge
        ]

    X = np.vstack(df_list)

    y = np.concatenate([0 * np.ones(len(df_list[0])),
                        1 * np.ones(len(df_list[1])),
                        2 * np.ones(len(df_list[2])),
                        3 * np.ones(len(df_list[3]))
                    ])

    window = Window(length=30)

    X_, f, y_ = window.fit_transform(X, y)

    # Division
    X_train, X_test, y_train, y_test = train_test_split(f, y_, test_size=0.5, random_state=0)
    clf = RandomForestClassifier(n_estimators=10, max_depth=10, random_state=0).fit(X_train, y_train)

    plot_confusion_matrix(clf, X_test, y_test, normalize='all', display_labels=['Push Up', 'Squat', 'Abs', 'Lunge'], colorbar=False,cmap="Blues")

    plt.title("Matriz de confusión clasificador actividades")
    plt.savefig(path + "/confusion_matrix_multi_final_acc94.svg")

    y_pred = clf.predict(X_test)
    print(accuracy_score(y_pred, y_test))

    # Exportación del modelo
    with open("WorkoutClassifier.h", "w") as file:
        file.write(port(clf, classname="WorkoutClassifier", classmap={0: "Push Up", 1: "Squat", 2: "Abs", 3: "Lunge"}))


    # Modelo binario
    df_list = [
            df_pushups,
            df_squat,
            df_abs,
            df_lunge,
            df_rest
        ]

    X = np.vstack(df_list)

    y = np.concatenate([0 * np.ones(len(df_list[0])),
                        0 * np.ones(len(df_list[1])),
                        0 * np.ones(len(df_list[2])),
                        0 * np.ones(len(df_list[3])),
                        1 * np.ones(len(df_list[4]))
                    ])

    # Division
    X_train, X_test, y_train, y_test = train_test_split(f, y_, test_size=0.5, random_state=0)
    clf = RandomForestClassifier(n_estimators=10, max_depth=10, random_state=0).fit(X_train, y_train)

    plot_confusion_matrix(clf, X_test, y_test, normalize='all', display_labels=['Active', 'Rest'], colorbar=False,cmap="Blues")

    plt.title("Matriz de confusión clasificador binario")
    y_pred = clf.predict(X_test)
    print(accuracy_score(y_pred, y_test))

    # Exportación del modelo
    with open("WorkoutBinary.h", "w") as file:
        file.write(port(clf, classname="BinaryClassifier", classmap={0: "Active", 1: "Rest"}))
