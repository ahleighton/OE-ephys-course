.. _refEDay4:

***********************************
Exercises Day 4
***********************************

.. |Ve| replace:: V\ :sub:`e`\
.. |Ce| replace:: C\ :sub:`e`\
.. |Rm| replace:: R\ :sub:`m`\
.. |Re| replace:: R\ :sub:`e`\
.. |Cs| replace:: C\ :sub:`s`\
.. |Vin| replace:: V\ :sub:`in`\
.. |Vec| replace:: V\ :sub:`ec`\
.. |Vout| replace:: V\ :sub:`out`\

.. contents::
  :depth: 2
  :local:

Bonsai
#######################################

Bonsai is a visual reactive programming language. It's great for data acquisition, because it can easily deal with multiple datastreams.

Some of these exercises were adapted from from Neurogears @ Wustl19, https://neurogears.org/wustl-2019/worksheets/acquisition/

Download and install Bonsai
**************************************

•	Download Bonsai from http://bonsai-rx.org.
•	Install Bonsai - Starter Pack from the package manager.

Video Acquisition
*************************************
Bonsai can be used to acquire and record data from many different devices. The first data type we will discuss is an image, which is represented as a 2D matrix of pixels. Each pixel represents either a brightness value in a grayscale image, or a BGR colour value in a colour image.

Exercise 1: Saving a video
-----------------------------

.. image:: ../_static/images/EEA/videowriter.png
   :align: center

• Insert a CameraCapture source.
• Insert a VideoWriter sink.
• Configure the FileName property of the VideoWriter operator with a file name ending in .avi.
• Run the workflow and check that it generates a valid video file.

Audio Acquisition
*************************************
Audio data is captured at much higher temporal sampling frequencies than video. However, the data is typically buffered into chunks of multiple samples before being sent to the computer. Also, multiple audio channels can be acquired simultaneously in the case of a stereo microphone, or high-density ephys probes. For this reason, such multi-sample, multi-channel data is also typically represented as a 2D matrix of amplitude values, where rows represent channels, and columns represent time.

Exercise 2: Saving a WAV file
--------------------------------

.. image:: ../_static/images/EEA/audiocapture.png
   :align: center

• Insert an AudioCapture source.
• Insert an AudioWriter sink.
• Configure the FileName property of the AudioWriter operator with a file name ending in .wav.
• Make sure that the SamplingFrequency property of the AudioWriter matches the frequency of audio capture.
• Run the workflow for some seconds to record a file.



Exercise 3: Trigger an auditory stimulus
--------------------------------------------


.. image:: ../_static/images/EEA/audioplayback.png
  :align: center

• Insert an AudioReader source.
• Configure the FileName property to point to the audio file you recorded in Exercise 3.
• Insert an AudioPlayback sink.
• Run the workflow and check that the sound is played correctly.


.. image:: ../_static/images/EEA/audiokeydown.png
   :align: center

• Insert a KeyDown source (Windows.input).
• Set the BufferLength property of the AudioReader to zero, so that all audio data is read into a single buffer.
• Combine the key press with the audio data using the WithLatestFrom combinator.
• Right-click the WithLatestFrom operator. Select Output > Item2 from the context menu.
• Move the AudioPlayback sink so that it follows the selected Item2 member.
• Run the workflow and press a key. What happens if you press several keys?


Digital Output
*************************************

Exercise 4: Control an LED
--------------------------------

.. image:: ../_static/images/EEA/ledon.png
   :align: center

• Upload StandardFirmata to your teensy in the Arduino software (File/Examples/Firmata/StandardFirmata)
• In Bonsai: Insert a Boolean source.
• Insert a DigitalOutput sink.
• Set the Pin property of the DigitalOutput operator to 13. This is the LED pin of the teensy- it turns on the LED that is already attached to the board.
• Configure the PortName property to the COM of your Teensy.
• Run the workflow and change the Value property of the Boolean operator to toggle the LED on the Teensy on and off.
• Optional: Change the output pin to a different digital output pin. Connect an LED and a resistor to this pin through the breadboard and turn the LED on with Bonsai. The LEDs in your kit have three pins, you can treat them as a normal LED by leaving one of the short pins unconnected.

Analog Inputs
*************************************

Exercise 5: Touch detector
--------------------------------

• Upload this :ref:`Firmata` to your Teensy
• In Bonsai, insert an AnalogInput node and configure it to Analog Pin 9.
• Run the workflow and tap the pin on the Teensy.

• Use the GreaterThan node to create a 'touch detector' that gives a 1 each time you tap the teensy.
• Run the workflow and tap the pin on the Teensy. What do you see?

This workflow is detecting each sample.

• Use the 'Buffer (Dsp)' and 'Average' nodes to run the detection over more than 1 sample. You will need to output only the first value from Average (it will by default return 4 values, and then the other nodes won't work as they can only receive 1 value.) Do this by right-clicking on Average/Output/Val0.

• Run the workflow and tap the pin on the Teensy.

.. raw:: html

  <details><summary> Workflow here:
  </summary>


.. image:: ../_static/images/EEA/Analogdetectbuffered.svg
   :align: center

.. raw:: html
  </details>

EMG into PC
######################################

Use the circuit from yesterday. Instead of reading into our oscilloscope, we will feed the signals to our pc through the Teensy microcontroller.

Shifting the signal
***********************************
The EMG signal is from -3 to +3V, but we can only digitize positive voltages. With a simple trick we can shift the signal up from -3 to 3V exactly into the 0-3V range we want, while still providing the amplifier with a -3 to +3V range.

.. container:: exercise


  A. Add a voltage divider to your EMG circuit

    .. image:: ../_static/images/EEA/eea_fig-64.png
      :align: center


    .. image:: ../_static/images/EEA/eea_fig-65.png
      :align: center


This voltage divider is not going to mess with our signal, because the signal is protected by the amplifier. You could in theory use almost any reasonable values for R, over 1kΩ, because the output impedance of the instrumentation amplifier is low and the input impedance (of the teensy analog input) is decently high. If you make R too small, this will still work on paper, but you’re now asking the op-amp to keep shovelling current into ground (or in this case, the 3V rail) through a small R, and eventually even an op-amp will get unhappy.

Streaming data from the microcontroller
****************************************

.. toctree::
  :hidden:

  Firmata.rst

We’re going to start streaming data to the pc, by using our Teensy microcontroller to digitize the analog signals we collect.

.. container:: exercise

  A. Connect the output from your amplifier to an analog input node on the Teensy as shown below. This is a 220 Ohm resistor across the instrumentation amplifier, and a voltage divider made of two equal resistors (anything above 1KOhm, see the text on ‘shifting the bipolar signal up’ below).

  B. Upload Firmata to the Teensy (code is in Arduino: Examples/Firmata/StandardFirmata )

  C. Open Bonsai and create an Analog Input node. Double-click to visualise your signal.

  D. Connect this to a 'Csv Writer' node to save your signals.
