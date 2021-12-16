
Why drawing current distorts signals
*****************************************
A perfect 5V voltage source would always provide exactly 5 Volts, no matter what the rest of the circuit looks like. If we put a lot of high impedance components in the rest of the circuit, less current will flow, and if we put low impedance components we will get a high current.

A real voltage source has a bit of output impedance, which means it acts as a voltage source in series with an impedance. This is modelled here:

https://tinyurl.com/yfvzdxbz

That invisible, small series resistance creates a voltage divider. Though the actual source voltage is the same 5V, the apparent voltage of the source varies depending on the ratio between the output impedance of the source, and the impedance of the rest of the circuit. The lower the impedance of the components used in the rest of the circuit, the higher the relative influence of the source output impedance, and the lower the apparent source voltage.

In our acquisition system, the voltage source are the potential changes in the extracellular fluid (Vec). The resistive and capacitive properties of the electrode create an output resistance. The relative impedance of the circuit before and after Vin influence the magnitude of the signal at Vin. If we allow a lot of current to flow from our electrode to ground, we have a low impedance circuit, and will distort our signal. We therefore need something that will stop current being drawn from our cells, and provide the necessary current itself from a different source. This is done by amplifiers, in the headstage.
