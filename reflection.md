# Reflections

---

## Component effects

The three components of a P(roportional)-I(ntegral)-D(erivative) controller have the following effects:

* P Term
  * The most intuitive of the terms, the proportional term drives the output in proportion to some control signal.  Here, we track the cross track error (CTE) which measures our distance from the center of the lane we and turn the steering wheel in proportion to how far from the center we are (i.e., the closer we are to going off road the harder we'll turn to correct toward center).
  * Without considering the other two parameters, this can lead to overcorrection and oscillatory, fishtailing behavior (P=0.2, I=0, D=0):

[P Controller](https://github.com/spillow/CarND-PID-Control-Project/blob/master/p_controller.mp4)

...

* D Term
  * To smooth out the P term behavior, it is useful to add a term that subtracts off the derivative of the cross track error.  This serves to act as a dampening factor that will more forcefully dampen the proportional term the more quicly it tries to change to cross track error by oversteering: (P=0.2, I=0, D=5):

[PD Controller](https://github.com/spillow/CarND-PID-Control-Project/blob/master/pd_controller.mp4)

* I Term
  * The integral term keeps track of the history of the cross track error by maintaining a running integral (or sum here).  This is especially effective if there is a consistent bias in the operation of the PD controller such that we would never see the cross track error go to zero.  This term would seek to push the control signal to drive the error to zero.
  * Without any bias in the simulator (e.g., misaligned wheels) the PD controller was by itself sufficient for good performance.

## Hyperparameter selection
  * the proportional parameters of the three terms were derived manually via a process similar to Sebastian's described "twiddle" method.  If the simulator could be operated in a non-graphical mode to more easily automatically drive it then it would be interesting to see the maximal performance that could be obtained.
