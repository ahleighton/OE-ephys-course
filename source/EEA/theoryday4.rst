.. toctree::
   :maxdepth: 3

.. _refTDay4:

***********************************
Theory Day 4:
***********************************

Now that we have all the steps of our acquisition system, we can talk about how to digitize our signals and combine multiple datastreams.

.. raw:: html

    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 d-flex mx-auto" style = "max-width: 100%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-5.png" class="card-img-top">
          <div class="card-body">
          <h5 class="card-title" > Figure 1: The equivalent circuit of the electrode</h5>
          </div>
        </div>
    </div>

Talk: Acquisition and Synchronization
###################################
One of the most common pitfalls in Neuroscience is correctly synchronizing multiple datastreams. How do you know whether your imaging and electrophysiology are aligned in time? How many different clocks do you have on your set up, and which of those can you trust?

.. raw:: html

  <center><iframe width="982" height="552" src="https://www.youtube.com/embed/F0uwA3RUlB0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe></center>

Digitization
###################################
The purpose of digitization is to convert amplified signals into digital values. Why do we digitize neural signals? So that we can process and store them.
First, the output of the amplifier (Vout) should match the digitizer dynamic range. Your analog signal should ‘occupy’, as much as possible, all discrete values in the digitization range. In other words, digitization range should match maximum analog signal. If the dynamic range is too small the signal will saturate, and if it is too large it will decrease effective signal resolution.

.. raw:: html

    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 d-flex mx-auto" style = "max-width: 100%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-58.png" class="card-img-top">
        </div>
    </div>

If you have a voltage divider and an open-loop op-amp (comparator) you can already build a circuit that checks if your analog signal is above or below a certain value. Now instead of one voltage divider, you could have a whole ‘ladder’, creating intermediate values, and compare to these. This is an incredibly inefficient way to make an ADC.

Here’s what this may look like:

.. raw:: html

    <div class="d-flex col-lg-12 col-md-12 col-sm-12 col-xs-12 justify-content-center mx-auto" style = "max-width: 100%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-59.png" class="card-img-top">
        <a href="https://tinyurl.com/yadu834g " class="btn btn-light stretched-link">Simulator Link</a>
        </div>
    </div>

In practice, many ADCs still use the same basic idea of using op-amps as comparators, but instead of comparing millions of values to obtain a precise measurement, they generate a reference voltage from an internal DAC and adjust that until it matches the input voltage, or use some other clever tricks.

.. raw:: html

    <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 d-flex mx-auto" style = "max-width: 50%">
        <div class="card text-center intro-card border-white">
        <img src="../_static/images/EEA/eea_fig-60.png" class="card-img-top">
        </div>
    </div>

Typically AD converters have 12 to 16 bit resolution (4096 to 65536 discrete values) for neural signals, which is usually enough because of the size of the signals we want (spikes etc), and because the thermal noise floor of typical electrodes is similar to the achievable resolution anyway: better digitizers would just measure more of that noise. If you want to read more about that, have a look `here. <http://deuterontech.com/wp-content/uploads/2015/10/Deuteron_Noise_and_Interference.pdf>`_

Acquiring and synchronizing data with Bonsai
###################################
If you want to use Bonsai to work more on your EMG acquisition, you can find a helpful introduction `here <https://neurogears.org/wustl-2019/worksheets/acquisition/>`_. The most relevant of these exercises are available as a pdf here, :download:`ex_day_4 <../_static/images/EEA/day_4_bonsai.pdf>`, slightly adjusted for this course.

Project
###################################
The final part of the course is to work on your own project. This can really be about anything
you find interesting. Possibilities are:

- Hardware: expand on the EMG by adding filters or LEDs
- Software: use Bonsai to make a closed-loop experiment
- Simulator: build your own simulated circuit with different types of electrodes
- Theory: dig deeper into the topic that most appealed to you

When deciding on your project, try to break it down into steps. The best projects are designed to be
successful even if they are not complete.
