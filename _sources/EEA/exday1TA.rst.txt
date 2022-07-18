.. _refEDay1TA:

***********************************
Exercises Day 1 TA
***********************************

.. |Na+| replace:: Na\ :sup:`+`\
.. |Cl-| replace:: Cl\ :sup:`-`\
.. |Ca2+| replace:: Ca\ :sup:`2+`\
.. |K+| replace:: K\ :sup:`+`\
.. |Rs| replace:: R\ :sub:`s`\
.. |Rm| replace:: R\ :sub:`m`\
.. |Re| replace:: R\ :sub:`e`\
.. |Rsh| replace:: R\ :sub:`sh`\
.. |Ce| replace:: C\ :sub:`e`\
.. |Csh| replace:: C\ :sub:`sh`\
.. |Vin| replace:: V\ :sub:`in`\
.. |Vec| replace:: V\ :sub:`ec`\
.. |Vout| replace:: V\ :sub:`out`\
.. |Ve| replace:: V\ :sub:`e`\
.. |Za| replace:: Z\ :sub:`a`\
.. |Ze| replace:: Z\ :sub:`e`\

.. contents:: Table of Contents
  :depth: 2
  :local:

.. container:: tabox

   Day 1!
   For many students, day 1 is about getting to know the equipment & using the right names for everything. Unless students are already very confident, it's best to take everyone through day 1 as a group. Particularly at this point, it's better to over-explain and repeat than risk people getting lost.

   - Show them the probes for the oscilloscope. Explain how to use the little hook, and show them the ground probe.

   - Check they understand the multimeter and oscilloscope and what they're measuring.

   - Make sure they can scale their picoscope software.

   - Explain which parts of the breadboard are connected, and which are not.

   - Check that everyone has a nice signal each time before moving on.

1.	Using a multimeter
###################################

.. container:: exercise

    Setup:

    - Make sure the multimeter has 2x AAA batteries installed.
    - Put the red probe in the port marked ‘VmAuA’ to indicate you want to measure Voltage (V), milliAmps (mA), and Resistance (Ohms). We won't use it in this course, but the 10Amax port can be used to measure high currents.
    - Insert the black probe in the port marked COM (= Common, which will be your ground).

    1A.	Set the multimeter dial to ‘Ω’. Use your multimeter to measure the resistance of any 3 different resistors in the kit. Check whether the resistance values you read correspond to the coloured bands on the resistors. How is your multimeter measuring this resistance?

    1B.	Now set your multimeter to measure the voltage across a AA battery. What voltage do you measure? What does it mean if you record a negative voltage?


.. container:: tabox

  Setup: Students have to remove the orange cover of the multimeter to insert the batteries, and need a screwdriver.

  1A: To measure resistance, the multimeter generates a voltage at both probes, and measures the current generated between them.

  1B: Should be around 1.2-1.5 V, unless it's used. If you record a negative voltage you just have to switch the lead around, it’s convention: the positive side of the battery should be the red. Students can use this later in the course (and in life) during troubleshooting, to make sure depleted batteries are not the issue.


Solderless Breadboard
***********************************
We are going to build many circuits during this course using components such as resistors, capacitors, and amplifiers. We are going to use a solderless breadboard to form an electrically conductive connection between these components.

Below is an example breadboard with the backing peeled off, to show what happens inside. Each hole in the breadboard provides access to a metal bar. Inserting a component into the hole connects it electrically to any other component that touches the same bar. Batteries or a different type of power supply are connected to the long 'rails' that run along the side of the board, to power the circuit.

.. image:: ../_static/images/EEA/exposed_breadboard.png
  :align: center

.. image:: ../_static/images/EEA/breadboard_connectivity.png
  :align: center

The most important thing is to remember which holes are connected. Your long breadboard is actually made up of two separate breadboards; as you can see above, the power rails run through rows 0-30 and 31-60. If you want to use the entire length of the breadboard, you will have to connect these rails together with wires.

If you need to, refer back to the `reading material <https://learn.sparkfun.com/tutorials/how-to-use-a-breadboard/all#anatomy-of-a-breadboard>`_ for the overview on how to use a breadboard, it also includes some basic troubleshooting which may prove useful if you run into problems.

Teensy Microcontroller
**********************************
In your kit you will find a Teensy LC. This is a microcontroller, like an Arduino (just a different brand). It is basically a small computer, that can only run 1 program at a time. Using the USB cable provided, you can upload a new programme to the Teensy. Whenever the Teensy is provided with a power source it will try to run that programme.

The Teensy can perform many different functions, such as generating output voltages or collecting input signals. To do so, it has specialised connectors around the edges of the board. These are called 'vias' or 'pins'. The 'pinout' below tells you what each pin of the Teensy can do. For instance, the pin marked '20' on the board is Digital Pin 20 (grey) and Analog pin 6.

.. image:: ../_static/images/EEA/teensy_LC.png
  :align: center


It’s important to distinguish between:

* Ground pins (GND)
* Analog pins, that can read varying voltages, such as a wave.
*	Digital pins, that can read or write HIGH or LOW values.

Some pins can perform multiple functions. For instance, the pin marked '20' on the board is Digital Pin 20 (grey) and Analog pin 6.

.. warning::
  We’re going to attach the Teensy to our solderless breadboard. Removing and replacing the teensy can sometimes bend the pins, so we’re going to leave it here for the whole course. If you do have to remove the teensy from the board, never hold it by the USB port, as it can easily snap off and can't be fixed!

.. image:: ../_static/images/EEA/teensy_on_board.png
  :align: center

.. container:: exercise

	Setup:
  - Attach the teensy to the left of your breadboard as shown above. If you make sure the breadboard is in the same orientation as this schematic, it will make the following exercises easier to follow.
  - Use the USB to micro-USB cable in your kit to connect the Teensy to your computer.
  - The Teensy comes with a default programme already loaded onto the board, so you should see the LED on the board start to blink slowly as soon as it is powered on.

  1C.	We can see that digital pin 13 has (LED) written beside it. Attach readout wires to the breadboard, and use your multimeter to find the voltage across the LED.

.. image:: ../_static/images/EEA/readout_teensy_voltage_schematic.png
  :align: center

.. image:: ../_static/images/EEA/readout_teensy_voltage_photo.png
  :align: center


.. container:: tabox

   Setup:

   If they need to upload the programme again, they can open the Arduino software: examples/basics/blink. Any problems, check:

   - Whether the board is set to Teensy LC under Tools/Board
   - The selected port Tools/Port

   1C:   Should be around 3.3V when high- they will see intermediate values too due to the low time resolution of the multimeter.


2.	Using an oscilloscope
###################################

Oscilloscopes let us measure time-varying voltages with much higher time resolution than the multimeter.

.. container:: exercise

    Setup:

    - Your Picoscope comes with two probes, you only need one. Connect it to the ‘A’ port on your oscilloscope.
    - Set the slider on the probe itself to ‘1x’.
    - Connect your PicoScope to your computer and open up the Picoscope software.

    2A. Use the PicoScope to measure the blink signal at the readout wires, as you did with your multimeter. Make sure you play around to find nice X and Y scaling. What shape & amplitude does the signal have?

    .. image:: ../_static/images/EEA/readout_teensy_voltage_picoscope.png
      :align: center

    If you see something odd, check:

    *	x-axis scaling (ms/div)
    *	y-axis scaling (Auto doesn’t always work)
    *	whether it is set to DC (direct current) or AC (alternating current).

.. container:: tabox

   2A: Should see a clear square wave of around 3.3 amplitude.

   .. image:: ../_static/images/EEA/blink_readout_picoscope.png
     :align: center


   NB: sometimes connecting the ground directly to the Teensy causes it to charge (you can see it with the scope) and it can end up disconnecting from the PC and making a mess. They don’t actually need the ground of the scope connected to see the large sine wave because of the scope’s high input impedance. That might be confusing now, but should be clearer after talking about impedance tomorrow.


   !!! If a student's scope isn't responding to any input, before panicking check that they are not using the 'automotive' version of the Picoscope software as this will make the scope look dead.


.. container:: exercise

  We’ll now upload a program that outputs a sine wave, instead of a blink.

  Setup:

  - Open the Arduino Software Upload the following code to your teensy:

  :ref:`sinewave`

  - Make sure that under ‘Tools/ Board’ your Teensy 3.2 has been found, and check which USB (COM) port it’s in (‘Tools/Port:).

  - If you see ‘Done Uploading’, the Teensy will start giving a sine wave as output from one of the analog output pins.

  2B.	Connect your oscilloscope probe to A12 and visualise the signal in your PicoScope software.

  .. image:: ../_static/images/EEA/sinewave_teensy_pico.png
    :align: center

.. container:: tabox

    Setup:

    - If they get an error ‘redefinition of void setup’ it’s because they dragged the sketch to the software,  then it gets added to the other sketch, needs to be uploaded separately.

    2B: Pin A14 is a DAC, digital to analog converter, so it can take the digital representation and output an analog(ish) sinewave. Make sure they don't get mixed up with digital pin 14 (analog pin 0).
    These exercises are just to check that they understand the value of having the oscilloscope over the multimeter- that knowing the shape of the signal is important. It helps to keep linking this back to their neural signals- what if you were undersampling them, you wouldn't see spikes. Make sure they are ok with the idea of alternating signals, and that digital and analog signals are clear as well.

    .. image:: ../_static/images/EEA/sinewave_output.png
      :align: center


3. Ohm’s Law
###################################
During this course, we’ll be using a circuit simulator to build circuits online. This allows us to quickly test our ideas and understanding, and make predictions about what will happen when we build the circuit in real life.


Ohm’s law describes how potential (V), current (I) and resistance (R) are related:

.. math::

  V = IR

When looking at a whole circuit, we can use this to calculate how much current will flow. Here is a simple circuit with a battery and two resistors. Current flows from the positive terminal of the battery to the negative terminal of the battery. The resistors are 'in series' as there is only 1 path for current flow.

.. image:: ../_static/images/EEA/resistors_series_sim.png
  :align: center
  :target: https://tinyurl.com/y4r8nsnj

.. container:: exercise

    3A. Click on the image to go to the simulator.
    Right-click on the top wire in the circuit, and then select Edit to display the current through that wire. Double-click on either of the resistors to decrease their value. What happens to the current in the circuit?

.. container:: tabox

  3A: The current should increase with decreased circuit resistance. The current change affects the entire circuit; current is the same everywhere.

4.	Resistors
###################################
Here’s another simulation demonstrating Ohm’s law. This time, the current moves from a 5 Volt voltage source (bright green) into ground (grey, earth), across one of two resistors. The resistors are 'in parallel' as current can flow cross over one *or* the other resistor.

.. image:: ../_static/images/EEA/resistors_parallel_sim.png
  :align: center
  :target: https://www.falstad.com/circuit/e-ohms.html

.. container:: exercise

  Setup:

  - Click the image open the simulator.
  - Right click on a resistor and select 'View in new scope'.
  - Do the same for the other resistor. You can click 'Reset' to restart the simulation and synchronise the scopes.

  4A. What do you predict will happen to the voltage over the left resistor if you double its resistance? What will happen to the current?

  4B.	What will happen to the voltage and current over the right-hand resistor when the other doubles in resistance?

  Now double the value of the left-hand resistor in the simulator and see if your predictions were correct.

.. container:: tabox

    Students can get confused about using Ohm's law over a whole closed circuit (to get current) and over individual components (voltage drops). It helps to remind them at which points in the circuit current must be equal and where voltage must be highest and lowest. Check that they understand why the current across these two resistors can be different, but not in the closed circuit above.
    Decreasing the resistance of any of the two resistors increases the current since they are in series and V = I * (R1+R2). Changes the ratio of the resistors changes the voltage drop over each resistor.

    4A: The voltage will not change; voltage over both resistors is the same as they are connected in parallel to a 5V source. The current will vary in proportion to resistance, so it will halve if the resistance doubles.

    4B: Nothing will change for this branch of the circuit.

    Circuit analysis refresher:
    - In series: same current flowing through components.
    - In parallel: same voltage across components.

    Methods for solving a circuit: Equivalent https://www.khanacademy.org/science/in-in-class10th-physics/in-in-electricity/in-in-solving-a-circuit-with-series-and-parallel-resistors/v/solved-example-finding-current-voltage-in-a-circuit and more advanced methods https://www.khanacademy.org/science/electrical-engineering/ee-circuit-analysis-topic/ee-dc-circuit-analysis/a/ee-circuit-analysis-overview

5.	Voltage Divider
###################################
In simulator
***********************************
Voltage is always measured relative to a point that we consider 0V. For a battery, the negative terminal is 0V.

Voltage (potential energy) ‘drops’ over each resistor, as potential energy is converted to another form of energy such as heat or light. In a circuit powered by a 9V battery, all 9V of potential energy from our battery source *must* drop over circuit components, to return to 0V at the negative terminal of the battery.

In each circuit below, the current through R1 must equal the current through R2, as they are resistors in series. Following Ohm's law, given the same current, a higher resistor will have a higher voltage drop (V=IR). The total voltage drop over the circuit must equal the provided voltage.

.. image:: ../_static/images/EEA/voltage_divider.png
  :align: center

Therefore, in a circuit with multiple resistors in series, the ratio of their resistances determines how much voltage will drop over each. We can therefore split up (divide) the voltage from a source across resistors to produce an output voltage |Vout|:

.. math::

  |Vout| = |Vin| \frac{R2}{R1+R2}


.. container:: exercise

  5A.	Using the simulator (here’s an empty full-screen https://tinyurl.com/y477e9qd) build a voltage divider circuit in which you use:

  - a 3V battery ('Draw' a 1-terminal voltage source set to 3V)
  - 2 resistors
  - a readout wire (right click and 'Edit' to show the voltage |Vout|)

  To provide an 2.1V output voltage |Vout| at the readout wire.


.. container:: tabox

   5A: Example answer:

   .. image:: ../_static/images/EEA/voltage_divider_sim_solution.png
     :align: center
     :target: https://tinyurl.com/y3fshb8c

   Sparkfun overview:
   https://learn.sparkfun.com/tutorials/voltage-dividers/all#extra-credit-proof


On breadboard
***********************************
We’ll now build the circuit you just designed in real life, using a solderless breadboard.

.. container:: exercise

  5B.	Use the battery holder and two AA batteries to create a 3V source. Use any two resistors from your kit to build a voltage divider, as shown below. If your multimeter doesn’t fit in the breadboard holes, you can place a short piece of 'readout' wire at each point you want to measure.

  .. image:: ../_static/images/EEA/voltage_div_breadboard_photo.png
    :align: center

  .. image:: ../_static/images/EEA/voltage_div_breadboard_schematic.png
    :align: center

  Bonus exercise: Replace one of the resistors to make your output voltage as small as you can get it. What’s the smallest reading you can still pick up with your multimeter? How does this compare to the amplitude of a spike measured in the extracellular space?

.. container:: tabox

   5B: This should work with a 1k and 2.2k resistor as shown.
   Bonus: The amplitude of a spike in extracellular space is around 100 uV. This should help them to realise how little that is.


6. Capacitors
###################################

.. warning:: Always check whether your capacitors are polarised or non-polarised.

Polarised capacitors must be used in a specific orientation. Usually, ceramic (the yellow ones in your kit) capacitors are not polarised and you can use them in either direction, whereas tube-shaped electrolytic capacitors (the black and blue ones in your kit) **are** polarised. The negative pin is indicated by a ‘-’ marking, and the positive leg is often longer.

:ref:`As discussed in the Theory handout <refcapacitancetheory>`, capacitors occur wherever charge can be separated along two conducting surfaces, separated by an insulating material that prevents the plates from touching. Cell membranes are capacitors, as are electrodes.

.. math::

  Q = C * V

The amount of charge (Q) a capacitor can separate depends on is its capacitance (C, measured in farads) and the voltage (V) across the capacitor.

.. image:: ../_static/images/EEA/capacitor_membrane.png
  :align: center
  :target: https://tinyurl.com/y5nglnv7

.. container:: exercise

  Setup:

  .. note::

    When you have capacitors in the simulator, it is a good idea to click 'reset' whenever you make changes, as they will otherwise store charge and can create weird effects.

  The simulator shows a simplified 'cell membrane' represented as a capacitor and a resistor. Changing the intracellular voltage supply changes the voltage across the cell membrane. The extracellular fluid is always 0 V.

  6A. The initial voltage over the capacitor is -72mV. Click 'Reset' to see current move through the circuit until the capacitor is charged to 72mV. Which direction is the current flow? Why does current stop moving?

  6B. Using the 'Voltage' slider, set the voltage supply to 0 mVolts, and then to 20mV. What happens to the current flow in the circuit?

  6C. Can you mimic an action potential by changing the intracellular voltage?

.. container:: tabox

   6A. Direction: Current flows into the cell, towards the power supply, as it is more negative than 0. Current flows until the capacitor is fully charged. Because charges can't actually move through the capacitor, but have to interact with each other over the insulating material, once the plates are fully charged no more current can flow.

   6B. Current will start to leave the cell. When we increase the voltage difference over the capacitor, we are providing more charges on 1 side of the capacitor, which can then influence the charges on the other side. Equally, when we decrease the voltage difference, charges are released which result in current flow.

   6C. Move from -70mV up to +20mV, back to -90mV and return to -70mV :)


.. container:: exercise

  Setup:

  Using the breadboard, build a circuit to charge and discharge one of the large capacitors in your kit. Use a 2.2KOhm resistor.

  .. image:: ../_static/images/EEA/charging_cap_schematic.png
    :align: center

  .. image:: ../_static/images/EEA/charging_cap_photo.png
    :align: center

    6D.	You will need to move the + leg of the cap (where the oscilloscope probe is) between GND and +3V. In the schematic, the + leg is connected to GND; it is discharging. The photo shows it connected to +3V (left) and connected to GND (right). When you move it, you should see it charge and discharge in your PicoScope trace. How long does it take for the capacitor to charge?

  6E.	Increase the value of the resistor. What does this change in your trace? Can you explain why?


.. container:: tabox

    6D & E: Results should look like figure below. Top panel: 220 kOhm, lower panel:very low resistance. Why? Because the resistor is setting the current through the circuit, determining how fast the capacitor is allowed to charge.

    .. image:: ../_static/images/EEA/cap_charging_picoscope.png
      :align: center

7. Alternating signal (AC)
###################################
Batteries provide 'direct current' in a single direction. In contrast, the action potentials and LFPs we measure from neurons can go in both directions; they are **alternating currents**. You produced an alternating current yourself in exercise 6C.

Alternating currents have a frequency, which is the rate at which they alternate direction. Action potentials have a very high frequency, whereas synaptic inputs and their sums are much slower.

Here is a demo where an alternating signal increases and decreases in frequency. At the bottom of the page, you can see the wave visualised.

.. container:: exercise

  7A.	Press ‘Play Audio’ to hear how the sound is modulated as the frequency increases.

  .. image:: ../_static/images/EEA/audio_sweep.png
    :align: center
    :target: https://tinyurl.com/yyrvugha


8. Impedance
###################################
Alternating currents have a frequency, so we need to use the term 'Impedance' (Z) instead of 'Resistance' to describe how circuit components oppose current flow. See the theory handout for more information.

The impedance magnitude of a capacitor, also called reactance (X\ :sub:`c`), depends on:

.. math::

   Xc = \frac{1}{2 \pi fC}


Where f is the frequency with which the current alternates, and C is the capacitance.

The impedance provided by capacitors varies with frequency. Because we are interested in signals at specific frequencies (e.g. 1000Hz for action potentials), we have to make sure to build our recording circuit so that the frequencies we are interested in experience little opposition.

When you see a capacitor in a circuit, you know you need to think about the frequency of the signal. Steady direct current has no frequency, so X\ :sub:`c` is infinite: capacitors only pass alternating signals.

.. container:: exercise

    .. image:: ../_static/images/EEA/cap_freq_circuits.png
      :align: center
      :target: https://tinyurl.com/y3sbgfl6

    Setup:

    Here are two circuits with an alternating voltage source of 15 and 40 Hz, respectively. In the oscilloscope at the bottom of the simulator, the voltage trace of the source and the capacitor are plotted.

    8A.	Visualise the current in the circuit (for instance the current flowing through the stretch of wire). You could add a new scope to do this or double-click the wire and 'show current'. Which circuit has higher amplitude current?

    8B.	Add a third circuit, powered by an alternating voltage source of 120 Hz. What happens to the current as the frequency increases?

    (Bonus question: what happens to the voltage drop across the capacitor as frequency increases?)


.. container:: tabox

   8A. The 40Hz circuit below has a max current of 20mA, the above circuit has a max of only 12mA.

   8B. This new circuit will have a max current of 24.4 mA.

   With increasing frequency, the impedance of the capacitor decreases. That means that:
   - The overall current in the circuit increases (I = V/R with lower R)
   - The ratio of impedance between the 200 Ohm resistor and the capacitor changes. It's another voltage divider: the 5 volt must still be 'spent' in the circuit, but more of it now goes to the 200 Ohm resistor. The voltage drop over the capacitor reduces as its impedance reduces.


9. Capacitive voltage divider
###################################
Because capacitors impede current flow, we can use them to build voltage dividers, just like the resistor divider shown above.

.. container:: exercise

  .. image:: ../_static/images/EEA/cap_voltage_div.png
    :align: center
    :target: https://tinyurl.com/yxdwvulv

  9A.	Change the capacitance values C for the first capacitor to test whether the formula for the resistor voltage divider applies for capacitors.


.. container:: tabox

   9A. At a fixed frequency we can use the ratio of capacitor impedance to create a voltage divider just as for resistors.

.. container:: tabox

    Wrap Up

    If they don't make it through all the exercises that's ok, but concepts that they should understand are:

    - What is an oscilloscope measuring?

    - How does a voltage divider work?  (this keeps coming back during the course)

    - What is the important difference between capacitors and resistors? (Frequency-dependent impedance changes of capacitors, also keeps coming back)
