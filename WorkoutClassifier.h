#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class WorkoutClassifier {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        uint8_t votes[4] = { 0 };
                        // tree #1
                        if (x[20] <= -55.24545478820801) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[13] <= 27.640975952148438) {
                                if (x[37] <= 21.450335025787354) {
                                    votes[3] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        // tree #2
                        if (x[16] <= -105.03999710083008) {
                            if (x[1] <= -20.74500060081482) {
                                votes[1] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[20] <= -14.091212511062622) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[4] <= -74.22954559326172) {
                                    votes[3] += 1;
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }
                        }

                        // tree #3
                        if (x[13] <= 17.93542766571045) {
                            if (x[21] <= 15.816916942596436) {
                                if (x[19] <= 61.38999938964844) {
                                    votes[3] += 1;
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[18] <= 13.025000095367432) {
                                if (x[12] <= 20.774242877960205) {
                                    votes[3] += 1;
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #4
                        if (x[16] <= -98.69000244140625) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[25] <= 62.255001068115234) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[19] <= 56.44499969482422) {
                                    votes[3] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #5
                        if (x[35] <= 89.84500122070312) {
                            if (x[2] <= 5.069999933242798) {
                                if (x[1] <= 0.1850000023841858) {
                                    if (x[45] <= 16.839358806610107) {
                                        votes[3] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }

                            else {
                                if (x[20] <= -14.091212511062622) {
                                    if (x[35] <= 77.27000045776367) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }
                        }

                        else {
                            if (x[25] <= 159.3650016784668) {
                                votes[0] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #6
                        if (x[19] <= 74.68000030517578) {
                            votes[3] += 1;
                        }

                        else {
                            if (x[12] <= 2.28621244430542) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[17] <= 38.42500114440918) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }
                        }

                        // tree #7
                        if (x[35] <= 89.84500122070312) {
                            if (x[11] <= 69.25500106811523) {
                                if (x[19] <= 57.3650016784668) {
                                    votes[3] += 1;
                                }

                                else {
                                    if (x[4] <= -60.438180923461914) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[13] <= 25.66480827331543) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[17] <= 80.5099983215332) {
                                    votes[3] += 1;
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }
                        }

                        else {
                            if (x[21] <= 22.74788188934326) {
                                votes[1] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #8
                        if (x[19] <= 73.7599983215332) {
                            votes[3] += 1;
                        }

                        else {
                            if (x[20] <= -57.721818923950195) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[2] <= 19.910000801086426) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #9
                        if (x[18] <= 13.025000095367432) {
                            if (x[4] <= -68.54439544677734) {
                                if (x[8] <= -25.980000495910645) {
                                    if (x[33] <= 41.90000057220459) {
                                        votes[3] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        else {
                            if (x[31] <= 20.5) {
                                votes[0] += 1;
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        // tree #10
                        if (x[18] <= 10.914999961853027) {
                            if (x[5] <= 36.0324182510376) {
                                if (x[19] <= 73.7599983215332) {
                                    votes[3] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        else {
                            votes[0] += 1;
                        }

                        // return argmax of votes
                        uint8_t classIdx = 0;
                        float maxVotes = votes[0];

                        for (uint8_t i = 1; i < 4; i++) {
                            if (votes[i] > maxVotes) {
                                classIdx = i;
                                maxVotes = votes[i];
                            }
                        }

                        return classIdx;
                    }

                    /**
                    * Predict readable class name
                    */
                    const char* predictLabel(float *x) {
                        return idxToLabel(predict(x));
                    }

                    /**
                    * Convert class idx to readable name
                    */
                    const char* idxToLabel(uint8_t classIdx) {
                        switch (classIdx) {
                            case 0:
                            return "Push Up";
                            case 1:
                            return "Squat";
                            case 2:
                            return "Abs";
                            case 3:
                            return "Lounge";
                            default:
                            return "Houston we have a problem";
                        }
                    }

                protected:
                };
            }
        }
    }