# Simulation of a Monosynaptic Neuronal Network

**Author:** Suchir Kohli  
**Entry Number:** 2022BB11381  

## Overview

This project simulates a simplified spinal pain circuit using the NEURON simulation environment. It includes three neuron types and models the influence of acetylcholine (ACh) and its receptors on chronic neuropathic pain processing.

---

## Project Objectives

- Simulate a 3-neuron nociceptive circuit:
  - Dorsal Root Ganglion (DRG) neuron (sensory input)
  - Glutamatergic Dorsal Horn neuron (excitatory relay)
  - GABAergic Interneuron (inhibitory modulation)
- Integrate biophysical ion channel dynamics (Na⁺, K⁺, Ca²⁺)
- Model excitatory/inhibitory synapses (AMPA, NMDA, GABAA)
- Simulate cholinergic modulation via AChR subtypes (α3β4, α4β2, α7)
- Analyze membrane potentials, ionic currents, and synaptic effects

---

## Installation

### Prerequisites
- [NEURON Simulator](https://neuron.yale.edu/neuron/) (version ≥ 7.8)
- Python (optional, for plotting outputs)

### Install NEURON

```bash
# Ubuntu/Debian (recommended)
sudo apt-get install neuron

# OR build from source
git clone https://github.com/neuronsimulator/nrn
cd nrn
./build.sh
make
make install
```

---

## Running the Simulation

### 1. Compile the MOD files

Open a terminal in the project root directory and run:

```bash
nrnivmodl modfiles
```

This will generate a `x86_64` folder containing compiled mechanisms.

### 2. Launch NEURON and run the simulation

```bash
nrngui simulation/driver.hoc
```

This will initialize the network, apply stimulation, and display membrane potential plots and current traces.

---

## Results Summary

- DRG neuron fires action potentials
- GABAergic interneuron exhibits rhythmic firing
- Glutamatergic neuron shows subthreshold activity
- Minimal AChR influence observed in current configuration

---

## Limitations

- Weak synaptic calcium response
- Simplified neuron morphologies
- Static ACh levels without ligand kinetics

---

## Future Work

- Tune receptor kinetics and conductance
- Add plasticity (e.g., LTP)
- Introduce metabotropic receptors
- Use empirical conductance values

---

## References

- [NEURON documentation](https://neuron.yale.edu/neuron/)
- [ModelDB](https://senselab.med.yale.edu/ModelDB/)
- Carnevale & Hines (2006), *The NEURON Book*
- [Albuquerque et al., 2009](https://doi.org/10.1152/physrev.00015.2008)

---

## Appendix

All simulation scripts are provided in the repository. Clone and run the simulation to explore nociceptive signaling and cholinergic modulation.

---
