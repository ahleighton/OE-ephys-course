.. _refEDay3TA:

***********************************
Exercises Day 3 TA
***********************************

.. contents::
  :depth: 2
  :local:

1. Differential Signals
###################################

.. container:: exercise

  1A.	Use the oscilloscope 1x probe to measure the electrical noise in your environment, for instance by touching the probe tip. How big is the amplitude of this signal? Compare this to the size of a spike, around 100 µV. Could you see a spike on top of that noise?

.. container:: tabox

  1A. This is just to show how noisy the world is, it will vary a lot depending on location.

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
  :target: https://tinyurl.com/yedcnfp4


.. container:: exercise

  2A. Connect the reference and spike signal to the op-amp in open-loop configuration to subtract the reference. Connect the output of the amplifier to the PC. Run the simulation. What (in V) is the amplifier giving as output?

  2B. Try adding a wire (with no resistors) as a negative feedback connection to stop the amplifier from saturating. Why does this not work?

  2C. Using two resistors to make a voltage divider on each side of the '-' input.
  What is the output now?

  2D. We're still not outputting our spikes. What went wrong?
  Try to figure this out but talk to a classmate or a TA if you get stuck.

  **Check that your have a correct differential amplifier circuit before moving on.**

.. container:: tabox

   2A:

   .. image:: ../_static/images/EEA/open_loop_ref.png
     :align: center
     :target: https://tinyurl.com/yemp5rve

   The amplifier is saturating because it is in open loop configuration; it has a huge gain.

   2B:

   .. image:: ../_static/images/EEA/singular_matrix.png
     :align: center
     :target: https://tinyurl.com/y2g8xpvc

   The simulator won't run, and complains of a 'singular matrix!' (bottom left). They need at least 1 resistor for the simulator to not give an error, because otherwise, they are asking 1) the output of the amplifier, 2) the - input of the amplifier and 3) the reference 60 hz signal to all initiate at the same voltage, because they are directly connected by a wire- basically short circuited. They can't possibly have the same voltage, as the amplifier's job is to output what keeps its + and - at the same value, which includes the spiking signal that the 60 hz doesn't have, so the simulator can't solve the circuit. Get rid of the 60 Hz source and it runs again.

   In case a student tries with 1 resistor: Why does putting just one resistor cause saturation? In that case, the (-) input would be receiving 60Hz 5V signal and trying to output the 120Hz 10mV difference that it is seeing on the (+) input to try and match both inputs. The amplifier does everything it can to make the - input equal to the + input. It outputs a voltage trying to increase the voltage at - every time there is a spike. But, because the - input is directly connected (via only a wire) to the voltage supply, it *must * have the same voltage as the voltage supply. Otherwise we'd have two different voltages in the same wire. The amplifier keeps reading that it has not succeeded to bring the - to the + level so it keeps its connection to the + rail, outputting the max voltage it can, i.e. saturating. All the voltage it outputs is actually lost over the resistor.
   Here's a simplified circuit with a direct voltage source instead of alternating just to  keep it simple. https://tinyurl.com/yyrs7o6t
   If you change the voltage on the variable voltage source on the right hand side, you can see that increasing the provided voltage only causes the voltage drop over the resistor to increase

   2C:

   .. image:: ../_static/images/EEA/neg_feedback_voltage_div.png
     :align: center
     :target: https://tinyurl.com/y5h9uuv4

   2D:

   The above does not work because the 60Hz reference signal '-' is being split in 2 by the resistor voltage divider, whereas the measurement signal '+' is not. The amplifier is outputting the voltage required to make the voltage at '-' match the voltage at '+'. Right now, it will  We need to apply the same division to the incoming signal from the measurement electrode.

   We therefore put '+' in the middle of a voltage divider to ground. yay this is a diff amplifier! https://tinyurl.com/y2qvrk9b

   .. image:: ../_static/images/EEA/diff_amp.png
     :align: center
     :target: https://tinyurl.com/y2qvrk9b


.. container:: exercise

  2E. In the simulator we are working with 'perfect' components. In real life, these parts have to be physically produced and have certain degrees of precision, called 'tolerances'. A resistance with 10% tolerance can be 10% higher or lower than the stated value.
  Simulate a case in which one of the resistors in the differential amplifier is 10% higher and another is 10% lower. What happens?

  |

  Return the resistors to balanced values. Now add resistors directly after the input signals, to act as your electrode (for both the signal and reference). You can simplify the electrode to a 300kOhm resistor, or a 800 pF capacitor if you prefer.


  2F. What happens to the signal if there is a 5% difference between the impedance of your 2 electrodes?
  Can we use this shiny new differential amplifier to record neural signals?

.. container:: tabox

  2E. The voltage divider will no longer be perfect, and more of the shared sinusoidal 'noise' signal from the inputs will be visible in the output.

  2F. The same as above. The idea of this is that students may already know that they can never gold-plate their electrodes to the exact same impedance, and this shows them how that would affect the circuit were we to use a differential amplifier like this.

  .. image:: ../_static/images/EEA/diff_amp_unbalanced_resistors.png
    :align: center
    :target: https://tinyurl.com/y5uu48hw


We worked hard to avoid drawing current from our frail electrode signal, and now we’re telling you to put big voltage dividers right at the inputs of our op-amp? That seems bad.

Also, as we’ve just simulated, often op-amps do not have equal input impedances across their inputs, in fact in practise it is often impossible to exactly match impedances. If you've ever measured electrode impedance, you will have noticed that there is always some slight variation in impedance. To get this differential amplifier to work, each electrode and resistor would have to be identical, which is, in practice, impossible.

.. container:: exercise

  2G. How do we fix this issue? We want to:


  - Preserve the differential properties of the amplifier we just built
  - Not have voltage dividers sending part of our precious signal to ground
  - Not be sensitive to small differences in resistor impedance

  Discuss this with your group or TA if necessary, and try to build that circuit.

.. container:: tabox

   2G: Solution: use 3 op-amps. The first two act as buffers for the reference and measurement electrode, the third amplifies the difference between them. Then the differences in input impedances don't matter.
   https://tinyurl.com/yz8d8e67

   .. image:: ../_static/images/EEA/instrumentation_amp_simulator.png
     :align: center
     :target: https://tinyurl.com/yz8d8e67

   Here is a circuit to explain the gain resistor: https://tinyurl.com/2bwtenvz



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

  3B. Now attach the surface electrodes onto the ends of the electrode cable, and click the jack into the breadboard adaptor.

  Each electrode corresponds to a different pin on the breadboard adaptor:

    * Black cable = ground electrode = Ring 2
    * Blue cable = '-' (reference) electrode  = Ring 1
    *	Red cable = '+' electrode = Tip

  3C. Attach your oscilloscope as shown:

  .. image:: ../_static/images/EEA/board_emg_picoscope.png
    :align: center

  If you tap the electrodes, you should see the trace of your PicoScope respond. Troubleshoot your circuit until you do. Make sure your Picoscope responds to tapping your electrodes before continuing, and ask a TA for help if you get stuck.

.. container:: tabox

     Problems here are often:

     * Forgetting to connect both grounds rails with a wire
     * Using the wrong amplifier (the op amp)
     * Being offset by 1 position in breadboard. Get the group to help each other spotting small errors like that.

    If they have a lot of noise on their recording, try:

     •	Disconnecting from 60/50Hz contaminated ground by using laptop battery
     •	Twisting or braiding the cables

.. container:: exercise

  Setup: Place the measurement and reference electrode very close together, on the part of the forearm where you can feel a muscle when tensed. Place the ground on the elbow, where you can feel bone.  You should see a clear signal in the oscilloscope when you tense your muscles. Moving your arm will cause large motion artefacts so try to find a setup that gives you a consistent and clear signal.

  .. image:: ../_static/images/EEA/arm.png
     :align: center

  3D.	The resistor across the instrumentation amplifier sets the gain of the amplifier. Change the gain of the amplifier by changing Rg. What happens when the value for Rg is very low?


.. container:: tabox

  3D:
  With a larger resistor for Rg we get less gain. Formula for instrumental amplifier gain = (R3/R2){(2R1+Rgain)/Rgain}.

  Therefore, the lower the value for Rg the more gain we should get, for instance try going from 220 Ohm to 100 Ohm. I did not manage to get it to saturate, but in theory this could happen at really high gain.
