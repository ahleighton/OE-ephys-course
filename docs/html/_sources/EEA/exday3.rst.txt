.. _refEDay3:

***********************************
Exercises Day 3
***********************************

.. contents::
  :depth: 2
  :local:

1. Differential Signals
###################################

.. container:: exercise

  1A.	Use the oscilloscope 1x probe to measure the electrical noise in your environment, for instance by touching the probe tip. How big is the amplitude of this signal? Compare this to the size of a spike, around 100 µV. Could you see a spike on top of that noise?

2. Reference electrode
###################################

So far, we have only considered the signal coming into our recording electrode, relative to ground. We will now add a reference electrode in the simulator.

You can think of the small square waves as spikes you are trying to detect, and the sine wave (that both reference and your measurement electrode share) as the background. This background could be slow EEG signals or 50Hz noise, which is likely to be present at both electrodes.

Step-by-step, we are going to build our 'goal' circuit has the following properties:

- Input from a measurement electrode (spikes)
- Input from a reference electrode (common noise)
- Output: Reference subtracted from measurement, multiplied by gain
- Does not draw current from the electrode

.. image:: ../_static/images/EEA/sim_reference_electrode.png
  :align: center
  :target: https://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l3BWcBmWBOA7AFjA5AmMSADjGIDYIFIQlraBTAWjDACgBDEJ5ZckfCW6DiAoaNzdJReHCjyZ8NgHkQyYlgFYaWAlpoRIbAErDiorGn49BIS-wMhyNJDTfQEbAG7D8m+2YWVvL44PBQsIbyMOwAHnZgoWRodlhIYGihmn4gAAoAwmwARmoa4Fj+GDT4xMhQbPE8CP54UsgQafzZmgBCHADGANYA5gBOAPYArgB2ACYAOgDO8wAOS4srAJaDDIsN3MiWavihLOQpBEjdIMYMAGYMowzT-Qzrm8PTHAA2JsIYoT4oh4kE0QIUThc0QinkaBCSWAwvhSuB0WhAAEEALYrb6bO6bR5sADu-0B5GBfho4KMjSw+DoGGsGUZKWuAElpitJgAXJZgJYACh6AHElqslgBlLY7RYASn2TE0CAw6W0tAwFnRnO5fMW+CFxgAogAxBXxen8BDkOjNWgUuzogpC5S83UK0lME7+YIsTJ2YJGcblJyaHSQNAo9yyTA28gMkIh5BsYNEUPybSR2gRGNM60JiBJakp8Dp8NZmCyJn4NDINBpdoJmICcBsIA


.. container:: exercise

  2A. Connect the reference and spike signal to the op-amp in open-loop configuration to subtract the reference. Connect the output of the amplifier to the PC. Run the simulation. What (in V) is the amplifier giving as output?

  2B. Try adding a wire (with no resistors) as a negative feedback connection to stop the amplifier from saturating. Why does this not work?

  2C. Using two resistors to make a voltage divider on each side of the '-' input.
  What is the output now?

  2D. We're still not outputting our spikes. What went wrong?
  Try to figure this out but talk to a classmate or a TA if you get stuck.

  **Check that your have a correct differential amplifier circuit before moving on.**

  |

  2E. In the simulator we are working with 'perfect' components. In real life, these parts have to be physically produced and have certain degrees of precision, called 'tolerances'. A resistance with 10% tolerance can be 10% higher or lower than the stated value.
  Simulate a case in which one of the resistors in the differential amplifier is 10% higher and another is 10% lower. What happens?

  2F.

  Setup: Return the resistors to balanced values. Now add resistors directly after the input signals, to act as your electrode (for both the signal and reference). You can simplify the electrode to a 300kOhm resistor, or a 800 pF capacitor if you prefer.

  What happens to the signal if there is a 5% difference between the impedance of your 2 electrodes?
  Can we use this shiny new differential amplifier to record neural signals?


We worked hard to avoid drawing current from our frail electrode signal, and now we’re telling you to put big voltage dividers right at the inputs of our op-amp? That seems bad.

Also, as we’ve just simulated, often op-amps do not have equal input impedances across their inputs, in fact in practise it is often impossible to exactly match impedances. If you've ever measured electrode impedance, you will have noticed that there is always some slight variation in impedance. To get this differential amplifier to work, each electrode and resistor would have to be identical, which is, in practice, impossible.

.. container:: exercise

  2G. How do we fix this issue? We want to:


  - Preserve the differential properties of the amplifier we just built
  - Not have voltage dividers sending part of our precious signal to ground
  - Not be sensitive to small differences in resistor impedance

  Discuss this with your group or TA if necessary, and try to build that circuit.

3. EMG circuit
###################################

.. warning::
  Your kit contains surface electrodes that we will use for EMG. These measurements involve attaching yourself to a circuit, so follow these rules to be safe:

  A.	Do not use anything other than the recommended batteries to power your circuit. Do not connect your circuit to mains supply for power, ground, anything.
  B.	Only connect the EMG electrodes to one arm. Don’t attach them to both arms. This is to avoid any current travelling across your heart.
  C.	If you are using a laptop, disconnect your laptop charger & run from battery while the electrodes are attached to you. This is to prevent any surges from mains supply from backpropagating through your laptop, to you.

We now have all the steps of the acquisition in place to simulate a lab experiment. We are going to build an EMG circuit on the breadboard, using:

- The electrodes in your kit. The disposable electrodes in the kit are single-use, so do not attach them until you are sure your circuit is working and that you have the correct position (see below).
- The electrodes clip onto the cable with three wires. We’ll be using an audio-to-breadboard jack to get the signal from the electrodes into the breadboard.
- An instrumentation amplifier as our 'headstage'. `This <https://www.ti.com/lit/ds/symlink/ina129-ep.pdf?ts=1636717545454&ref_url=https%253A%252F%252Fwww.google.com%252F>`_ is the datasheet for the instrumentation amplifier in your kit.

.. image:: ../_static/images/EEA/instr_amp_pinout.png
  :align: center

- We will first test the circuit using the Picoscope to read out the signal. Tomorrow, we will use the Teensy as our acquisition board to digitize the data.

.. container:: exercise

  3A. Replicate the following circuit:

  .. image:: ../_static/images/EEA/fritz_emg_picoscope.png
    :align: center

  * Bypass capacitors = '104'
  * Gain resistor: 220 Ohm

  .. image:: ../_static/images/EEA/emg_gain_resistor.png
    :align: center

  3B. Now attach the surface electrodes onto the ends of the electrode cable, and click the jack into the breadboard adaptor.

  Each electrode corresponds to a different pin on the breadboard adaptor:

  * Black cable = ground electrode = Ring 2
  * Blue cable = '-' (reference) electrode  = Ring 1
  *	Red cable = '+' electrode = Tip

  3C. Attach your oscilloscope as shown:

  .. image:: ../_static/images/EEA/board_emg_picoscope.png
    :align: center

  If you tap the electrodes, you should see the trace of your PicoScope respond. Troubleshoot your circuit until you do. Make sure your Picoscope responds to tapping your electrodes before continuing, and ask a TA for help if you get stuck.

  |

  3D.

  Place the measurement and reference electrode very close together, on the part of the forearm where you can feel a muscle when tensed. Place the ground on the elbow, where you can feel bone.  You should see a clear signal in the oscilloscope when you tense your muscles. Moving your arm will cause large motion artefacts so try to find a setup that gives you a consistent and clear signal.

  .. image:: ../_static/images/EEA/arm.png
     :align: center

  The resistor across the instrumentation amplifier sets the gain of the amplifier. Change the gain of the amplifier by changing Rg. What happens when the value for Rg is very low?
