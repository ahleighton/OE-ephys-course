.. toctree::
   :maxdepth: 3

.. _refEDay1TA:

.. |Ve| replace:: V\ :sub:`e`\
.. |Ce| replace:: C\ :sub:`e`\
.. |Rm| replace:: R\ :sub:`m`\
.. |Re| replace:: R\ :sub:`e`\
.. |Cs| replace:: C\ :sub:`s`\
.. |Vin| replace:: V\ :sub:`in`\
.. |Vec| replace:: V\ :sub:`ec`\
.. |Vout| replace:: V\ :sub:`out`\

Exercises Day 1 (TA)
================================

*These docs have notes for teachers to help them give the course, it could also be helpful for people following the course on their own who need some help/hints/solutions.*

.. note::
  It's best to take everyone through day 1 as a group, show them the different probes for the oscilloscope, make sure they have AC/DC setting correct. Check that everyone has a nice signal each time before moving on.

We’re going to go through the basic electronics you will need to understand the equivalent circuit of the electrode, below:

.. raw:: html

    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 d-flex mx-auto" style = "max-width: 100%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-9.png" class="card-img-top">
          <div class="card-body">
          <h5 class="card-title" > Figure 1: The equivalent circuit of the electrode</h5>
          </div>
        </div>
    </div>

1.	Using a multimeter
***************************
    A.	Make sure the multimeter has batteries installed and is set to ‘Ω’. Put the red lead in the port marked ‘VmAuA’ and the black one in the port marked COM.
    B.	Use your multimeter to measure any 3 different resistors in the kit. Check whether the resistance values you read correspond to the bands on the resistors. How is your multimeter measuring this resistance?
    C.	Measure the voltage across a battery. What does it mean if you record a negative voltage?

.. note::
  To measure resistance, the multimeter generates a voltage at both probes, and measures the current generated between them.

In your kit you will find a Teensy 3.2. This is a small microcontroller that we can control in software, and use to generate output or collect input voltage signals. We’re going to attach it to our solderless breadboard.
If you need to, refer back to the reading material for the overview on how to use a breadboard, it also includes some basic troubleshooting which may prove useful if you run into problems. The most important thing is to remember which holes are connected. Your long breadboard is actually made up of two separate breadboards; + and – rails run through rows 0-30 and 31-60.
If you want to use the entire length of the breadboard, you will have to connect these rails together with wires.

.. raw:: html

    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 d-flex mx-auto" style = "max-width: 100%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-10.png" class="card-img-top">
          </div>
    </div>

D.	Attach the teensy to the left of your breadboard as shown above. If you make sure the breadboard is in the same orientation as this schematic, it will make the following exercises easier to follow. Removing and replacing the teensy can sometimes bend the pins, so we’re going to leave it here for the whole course.
E.	Use the USB to micro-USB cable in your kit to connect the Teensy to your computer. The Teensy comes with a default programme already loaded onto the board, so you should see the LED on the board start to blink slowly as soon as it is powered on.

.. note::
  If they need to upload the programme again, they can open the Arduino software: examples/basics/blink. Any problems, check:
  - Whether the board is set to Teensy under Tools/Board
  - The selected port Tools/Port

The kit includes a Teensy pinout card:

.. raw:: html

    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 d-flex mx-auto" style = "max-width: 100%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-11.png" class="card-img-top">
          </div>
    </div>

Each gold circle (‘via’) on this pinout represents an input or output of the Teensy. Your teensy already has pins attached, so that you can use it in your breadboard later. This diagram (‘pinout’) shows us what each pin of the Teensy can do. It’s important to distinguish between:

* Ground pins (GND)
* Analog pins, that can read varying voltages, such as a wave.
*	Digital pins, that can read or write HIGH or LOW values.

F.	We can see that digital pin 13 has (LED) written beside it. Attach readout wires to the breadboard, and use your multimeter to find the voltage across the LED.

.. note::
  Should be around 3.3V.

.. raw:: html

    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 d-flex mx-auto" style = "max-width: 100%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-12.png" class="card-img-top">
          </div>
    </div>

    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 d-flex mx-auto" style = "max-width: 100%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-13.png" class="card-img-top">
          </div>
    </div>

2.	Using an oscilloscope
**************************
A. Your Picoscope comes with two probes, you only need one. Connect it to the ‘A’ port on your oscilloscope.
B. Set the slider on the probe itself to ‘1x’. Connect your PicoScope to your pc and open up the Picoscope software.
C. Use the PicoScope to measure the blink signal at the readout wires, as you did with your multimeter. Make sure you play around to find nice X and Y scaling. What shape & amplitude does the signal have?


.. raw:: html

    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 d-flex mx-auto" style = "max-width: 100%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-14.png" class="card-img-top">
          </div>
    </div>

If you see something odd, check:

*	x-axis scaling (ms/div )
*	y-axis scaling (Auto doesn’t always work)
*	whether it is set to DC (direct current) or AC (alternating current).

.. note::
  Should see a clear square wave of around 3.3 amplitude. NB: sometimes connecting the ground to teensy causes it to charge (you can see it with the scope) and it can end up disconnecting from the PC and making a mess. They don’t actually need the ground of the scope connected to see the large sine wave because of the scope’s high input impedance. That might be confusing now, but should be clearer after talking about impedance tomorrow.

.. raw:: html

      <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 d-flex mx-auto" style = "max-width: 75%">
          <div class="card text-center intro-card border-white">
          <img src="../_static/images/EEA/eea_fig-66.png" class="card-img-top">
            </div>
      </div>


We’ll now use the Teensy microcontroller to output a sine wave, instead of the blink example.

D. Open the Arduino Software Upload the following code to your teensy:

:ref:`sinewave`

Make sure that under ‘Tools/ Board’ your Teensy 3.2 has been found, and check which USB (COM) port it’s in (‘Tools/Port:).
If you see ‘Done Uploading’, the Teensy will start giving a sine wave as output from one of the analog output pins.

.. note::

  If they get an error ‘redefinition of void setup’ it’s because they dragged the sketch to the software,  then it gets added to the other sketch, needs to be uploaded separately.

E.	Measure the output with your multimeter, from pin A14.

.. note::
  They should see a constant voltage of around 3.3 volts from A14 to GND, because their multimeter doesn’t resolve the signal fast enough to see the waveform. Pin A14 is a DAC, digital to analog converter, so it can take the digital representation and output an analog(ish) sinewave.

F.	Connect your oscilloscope probe to A14 and visualise the signal in your PicoScope software.

.. raw:: html

    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 d-flex mx-auto" style = "max-width: 100">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-15.png" class="card-img-top">
          </div>
    </div>

.. note::
  These exercises are just to check that they understand the value of having the oscilloscope over the multimeter- that knowing the shape of the signal is important. It helps to keep linking this back to their neural signals- what if you were undersampling them, you wouldn't see spikes. Make sure they are ok with the idea of alternating signals, and that digital and analog signals are clear as well.

3. Ohm’s Law
***************
During this course, we’ll be using a circuit simulator to build our circuits online. This allows us to quickly test our ideas and understanding, and make predictions about what will happen when we build the circuit in real life.
Ohm’s law describes how potential (V), current (I) and resistance (R) are related:

.. math::

  V = IR

When looking at a whole circuit, we can use this to calculate how much current will flow. Here is a simple circuit with a battery and two resistors. Current flows from the positive terminal of the battery to ground, which is the negative terminal of the battery.

.. raw:: html

    <div class="d-flex col-lg-12 col-md-12 col-sm-12 col-xs-12 justify-content-center mx-auto" style = "max-width: 100%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-16.png" class="card-img-top">
        <a href="https://tinyurl.com/y4r8nsnj" class="btn btn-light stretched-link">Simulator Link</a>
        </div>
    </div>

1.	Click on the above link to go to the simulator.
Right-click on the top wire in the circuit, and then select Edit to display the current through that wire. Double-click on either of the resistors to decrease their value and see how the
current in the circuit responds.

4.	Resistors
********************************************
Here’s another simulation demonstrating Ohm’s law. This time, the current moves from a 5 Volt voltage source (bright green) into ground (grey, earth), across one of two resistors.

.. raw:: html

    <div class="d-flex col-lg-12 col-md-12 col-sm-12 col-xs-12 justify-content-center mx-auto" style = "max-width: 100%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-17.png" class="card-img-top">
        <a href="https://www.falstad.com/circuit/e-ohms.html" class="btn btn-light stretched-link">Simulator Link</a>
        </div>
    </div>

A.	Display the voltage and current over both resistors in the ‘scope’ (right click/show in new scope). What will happen to the voltage over the left resistor if you double its resistance? What will happen to the current?
B.	What will happen to the voltage and current over the left-hand resistor? Double the value in the simulator and see if your predictions were correct.

.. note::
  Students can get confused about using Ohm's law over a whole closed circuit (to get current) and over individual components (voltage drops). It helps if they understand at which points in the circuit current must be equal and where voltage must be highest and lowest. Check that they understand why the current across these two resistors can be different, but not in the closed circuit above.

5.	Voltage Divider
************************************
In simulator
################
When we measure how much voltage is provided by a voltage source (such as a battery, or the output from the Teensy), we always measure it relative to a point that we consider 0V. In a circuit powered by a battery, we consider the negative terminal to be at 0V. If there is a connection to earth, or ground, this is taken as 0V.

Voltage (potential energy) ‘drops’ over each resistor, as potential energy is converted to another form of energy (such as heat or light). In a circuit powered by a 9V battery, all 9V of potential energy from our battery source *must* drop over circuit components, so that we end up back at 0V.

The higher the value of the resistor, the higher the voltage drop over it, but the total voltage drop over the circuit must equal the provided voltage.

.. raw:: html

    <div class="d-flex col-lg-12 col-md-12 col-sm-12 col-xs-12 justify-content-center mx-auto" style = "width: 150%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-18.png" class="card-img-top">
        </div>
    </div>

That means that, in a circuit with multiple resistors in series, the ratio of their resistances determines how much voltage will drop over each. We can therefore split up (divide) the voltage from a source across resistors. If we measure the voltage in between these resistors as |Vout|:

.. math::

  |Vout| = |Vin| \frac{R1}{R1+R2}

A.	Using the simulator (here’s an empty full-screen https://tinyurl.com/y477e9qd) build a voltage divider circuit in which you use a battery and two resistors to provide an 800 mV output voltage |Vout|.

.. note::
  Voltage divider circuits: https://tinyurl.com/yyh5amrz
  https://tinyurl.com/y5odbxa5

On breadboard
################
We’ll now build the circuit you just designed in real life, using a solderless breadboard.

B.	Use the battery holder and two AA batteries to create a 3V source. Use any two resistors from your kit to build a voltage divider, as shown below. If your multimeter doesn’t fit in the breadboard holes, you can place a short piece of wire at each point you want to measure.

.. raw:: html

    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 d-flex mx-auto" style = "max-width: 100%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-19.png" class="card-img-top">
          </div>
    </div>

    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 d-flex mx-auto" style = "max-width: 100%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-20.png" class="card-img-top">
          </div>
    </div>

.. hint::
  Bonus exercise: Replace one of the resistors to make your output voltage as small as you can get it. What’s the smallest reading you can still pick up with your multimeter? How does this compare to the amplitude of a spike measured in the extracellular space?

6. Capacitors
******************

.. warning:: Always check whether your capacitors are polarised or non-polarised. Polarised capacitors must be used in a specific orientation. Usually, ceramic (the yellow ones in your kit) capacitors are not polarised and you can use them in either direction, whereas tube-shaped electrolytic capacitors (the black and blue ones in your kit) **are** polarised. The negative pin is indicated by a ‘-’ marking, and the positive leg is often longer.

Capacitors, direct current
################################
Capacitors are made of two conducting plates, separated by an insulating material that prevents the plates from touching. Charges cannot jump through the insulating layer. Instead, charges collect on one plate, forming an electric field that pushes away similar charges on the opposite plate. This movement of charge is what gives us current flow in the circuit, even though charges cannot flow directly through the capacitor.

.. math::

  Q = C * V

The amount of charge (Q) a capacitor can separate depends on is its capacitance (C, measured in farads) and the voltage (V) across the capacitor.


In a direct current circuit, current will flow while the capacitor charges, as charge is pushed or pulled on either plate. Current flow will stop once the capacitor is fully charged. This electric charge can be discharged (and, for instance, used to power something) by providing a path that connects the positive and negative charges of the capacitor.
In this simulation, you can charge and discharge a capacitor and see the current flow through the circuit.

.. raw:: html

    <div class="d-flex col-lg-12 col-md-12 col-sm-12 col-xs-12 justify-content-center mx-auto" style = "max-width: 75%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-21.png" class="card-img-top">
        <a href="https://www.falstad.com/circuit/e-cap.html" class="btn btn-light stretched-link">Simulator Link</a>
        </div>
    </div>

A.	Modify the simulation to power an LED (Draw/Outputs and Labels/Add LED) by the capacitor as it discharges. The simulator will turn the LED red when it is on.

.. note::
  https://tinyurl.com/y5p5y5p2

B.	Using the breadboard, build this circuit to charge and discharge one of the large capacitors in your kit.

.. raw:: html

    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 d-flex mx-auto" style = "max-width: 100%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-22.png" class="card-img-top">
          </div>
    </div>

    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 d-flex mx-auto" style = "max-width: 100%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-23.png" class="card-img-top">
          </div>
    </div>

C.	In this configuration, you will need to move the + leg of the cap (where the oscilloscope probe is) between GND and +3V. In the schematic, the + leg is connected to +3V, in the photo it is connected to GND. You should see it charge and discharge in your PicoScope trace. How long does it take for the capacitor to charge?
D.	Change the value of the resistor. What does this change in your trace? Can you explain why?

.. note::

  Results should look like figure below. Top panel: 220 kOhm, lower panel:very low resistance. Why? Because the resistor is setting the current through the circuit, determining how fast the capacitor is allowed to charge.

.. raw:: html

    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 d-flex mx-auto" style = "max-width: 75%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-67.png" class="card-img-top">
          </div>
    </div>


Alternating signal (AC)
#########################
So far, we have mostly used resistances and Ohm's law to describe how the circuit resists direct current flow. This is applicable to direct current situations (such as batteries), but the action potentials and LFPs we measure from neurons can go in both directions- they are alternating currents. So, how do resistances and capacitors ‘resist’ alternate current flow?
Alternating currents have different frequencies. Action potentials cause very fast changes in current (and potential), whereas synaptic inputs and their sums are much slower. We have to make sure the frequencies we are interested in can travel through our recording circuit.
Here is a demo where an alternating signal increases and decreases in frequency. At the bottom of the page, you can see the wave visualised.

A.	Press ‘Play Audio’ to hear how the sound is modulated as the frequency increases.

.. raw:: html

    <div class="d-flex col-lg-12 col-md-12 col-sm-12 col-xs-12 justify-content-center mx-auto" style = "max-width: 100%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-24.png" class="card-img-top">
        <a href="https://tinyurl.com/yyrvugha" class="btn btn-light stretched-link">Simulator Link</a>
        </div>
    </div>

When we were only dealing with resistors, changes in our circuit happened instantly. We have seen that introducing a capacitor into our circuit means that we have to take time into account, as it takes time for the capacitor to charge and discharge. Resistors are not sensitive to changes in frequency, but capacitors are.

.. raw:: html

    <div class="d-flex col-lg-12 col-md-12 col-sm-12 col-xs-12 justify-content-center mx-auto" style = "max-width: 70%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-25.png" class="card-img-top">
        <a href="https://tinyurl.com/y3sbgfl6" class="btn btn-light stretched-link">Simulator Link</a>
        </div>
    </div>

Here are two circuits, both provided by an alternating voltage source with a different frequency. In the scope below, the voltage trace of the source and the capacitor are plotted.

B.	Change the simulator oscilloscope to display the current in the circuit (for instance the current flowing through the stretch of wire).
C.	Add a third circuit, powered by an alternating voltage source of 120 Hz. What happens as the frequency increases?

To describe restriction of direct current flow, we used resistance (R). To describe opposition to alternating current, we need to use the term Impedance (Z)and takes into account time-varying signals. We will discuss this in more detail tomorrow. For now, it is important to know that the impedance magnitude of a capacitor, also called reactance (X\ :sub:`c`), depends on:

.. math::

   Xc = \frac{1}{2 \pi fC}


Where f is the frequency with which the current alternates, and C is the capacitance. With increased frequency or capacitance, a capacitor will provide less restriction of current flow.

When you see a capacitor in a circuit, you know you need to think about the frequency of the signal. Steady direct current has no frequency, so X\ :sub:`c` is infinite: capacitors only pass alternating signals.

Capacitive voltage divider
###################################
Because capacitors impede current flow, we can use them to build voltage dividers, just like the resistor divider shown above. Here is an example:

.. raw:: html

    <div class="d-flex col-lg-12 col-md-12 col-sm-12 col-xs-12 justify-content-center mx-auto" style = "max-width: 70%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-26.png" class="card-img-top">
        <a href="https://tinyurl.com/y5kq7yct" class="btn btn-light stretched-link">Simulator Link</a>
        </div>
    </div>

A.	Try changing the capacitance values C for the first capacitor. How does this change your output voltage?

7. The equivalent circuit of the electrode
*********************************************
In the theory handout, we discussed how we can represent an electrode as a circuit containing a resistance and a capacitance. We’ll now build this equivalent circuit in the simulator. We will use this to examine the relationship between |Vec| and |Vin|, i.e., how faithfully the electrode transfers the signal from our neuron to our recording system.

A.	Use the simulator to build the equivalent circuit of the electrode as shown below:

.. raw:: html

    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 d-flex mx-auto" style = "max-width: 100%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-9.png" class="card-img-top">
          </div>
        </div>
    </div>

Here are some values to use:

*	|Rm|: the DC resistance of the metal electrode wire, 10-100 Ohms.
*	Ce: the electrode tip capacitance, generated by the double layer generated around the electrode.  |Ce| ~ 0.2 pF / µm2, so around 10 - 20 pF (if the electrode is unplated)
*	|Re|: electrode tip resistance, in parallel with |Ce|. ~ 10 to 100 MOhm.
*	|Cs| is the input shunt capacitance, due to the capacitance along the insulated portion of the electrode and wire (~50-100 pF).

B.	We can’t see much without an input signal. Add a 1KHz alternating voltage supply to mimic the signal coming from your cell.
C.	Visualise the 1KHz input in the scope.
D.	Add a new scope with the signal as seen by the end of the electrode wire. This allows us to compare the signal at the extracellular fluid (|Vec|) with what we’re getting out of our electrode (|Vin|). How are they different?

.. note::
  circuit of electrode: https://tinyurl.com/yg3bcugs

The DC resistance of the wire, |Rm|, is very low, so the voltage drop over it is tiny. We can treat this as a short circuit.

E.	Stop the simulation and remove this resistance. You should see that this hardly influences the relationship between the input and output of your electrode. We can therefore simplify our equivalent circuit by leaving this resistance out.
F.	|Re| and |Ce| are in parallel, and because |Re| has such a high resistance, little current will actually travel over this resistor: |Ce| will have a much bigger effect on the circuit. Simplify the circuit even further by deleting |Re|.

We’re left with our electrode and the long wire represented by two capacitors (|Ce| and |Cs|).
Above, we described a voltage divider made of two (or more) resistors. Capacitors in series can act as a voltage divider too, splitting the input voltage up according to the ratio of resistance (impedance in the case of capacitors) that they provide.

G.	What is the ratio between |Ce| and |Cs| at the moment? How much of our voltage |Vec| is reaching the output of our electrode, |Vin|?  What could we change to get more of our voltage signal reaching the output? Try changing values in the simulator to get a larger amplitude output signal.

Save your circuit (export as link/text)!

Wrap Up by TA
===============================
As a group, go through a simulation circuit of the electrode equivalent circuit with an alternating signal. Show that:
* A tetrode can’t drive this long wire with shunt capacitance
 	-- We draw a load of current
  -- We get tiny output signal
* Replace the wire with an amp.
 -- Now it doesn’t matter whether it’s a capacitor or a resistor!

To show this, you can use `this circuit. <https://tinyurl.com/yzh2vvuj>`_

Has a 1 kHz signal, and capacitor values similar to the ones they used in the electrode circuit above:


If this is still confusing, simplify it to a capacitive voltage divider and make sure at least that is clear:
`capacitive voltage divider circuit <https://tinyurl.com/yxg9bl56>`_

Show that you can change the ratio of capacitor values and see that though Cs is fixed, we can increase the capacitance of Ce to get more signal.

Acknowledgements
===============================
Written by:

* Alexandra Leighton
* Joana Neto
* Jakob Voigts
* Aarón Cuevas López
* Jon Newman

With material from:

* Joana Neto, 2018; Materials and neuroscience: validating tools for large-scale, high-density neural recording, 2018.
* Jon Newman and Jakob Voigts, 2017; Intro to Chronic Ephys (presentation at TENSS)
* Mitra Javadzadeh, 2017; Building an analog ephys recording system (practical exercises developed for TENSS)
* Circuit Simulator version 2.4.6js. Original by Paul Falstad, JavaScript conversion by Iain Sharp. 

Licensing
===============

This work is licensed under CC BY-SA 4.0. To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
