import numpy as np
import matplotlib.pyplot as plt

# Define parameters
binary_sequence = "1001110101"
A = 1  # Carrier amplitude
T = 1  # Bit period

# Carrier frequency
carrier_freq = 1 / T

# Time axis
t = np.linspace(0, len(binary_sequence) * T, 1000 * len(binary_sequence))

# Modulated signals
modulated_ook = np.zeros_like(t)
modulated_bpsk = np.zeros_like(t)
modulated_qpsk = np.zeros_like(t)
modulated_dbpsk = np.zeros_like(t)

# Modulation schemes
for i, bit in enumerate(binary_sequence):
    # OOK modulation
    modulated_ook[i * 1000 : (i + 1) * 1000] = A if bit == '1' else 0
    
    # BPSK modulation
    phase_shift = 0 if bit == '1' else np.pi
    modulated_bpsk[i * 1000 : (i + 1) * 1000] = A * np.cos(2 * np.pi * carrier_freq * t[i * 1000 : (i + 1) * 1000] + phase_shift)
    
    # QPSK modulation
    if i % 2 == 0:  # Grouping bits into pairs
        bit_pair = binary_sequence[i:i+2]
        if bit_pair == '00':
            phase_shift = 0
        elif bit_pair == '01':
            phase_shift = np.pi / 2
        elif bit_pair == '10':
            phase_shift = np.pi
        elif bit_pair == '11':
            phase_shift = 3 * np.pi / 2
        modulated_qpsk[i * 1000 : (i + 1) * 1000] = A * np.cos(2 * np.pi * carrier_freq * t[i * 1000 : (i + 1) * 1000] + phase_shift)
    else:
        # Copy previous modulated signal for non-data intervals
        modulated_qpsk[i * 1000 : (i + 1) * 1000] = modulated_qpsk[(i - 1) * 1000 : i * 1000]
    
    # DBPSK modulation
    if i == 0:
        prev_phase = 0
    else:
        prev_phase = np.arctan2(np.imag(modulated_dbpsk[(i - 1) * 1000]), np.real(modulated_dbpsk[(i - 1) * 1000]))
    phase_shift = 0 if bit == '0' else np.pi
    modulated_dbpsk[i * 1000 : (i + 1) * 1000] = A * np.cos(2 * np.pi * carrier_freq * t[i * 1000 : (i + 1) * 1000] + prev_phase + phase_shift)

# Plotting
plt.figure(figsize=(12, 8))

plt.subplot(411)
plt.plot(t, modulated_ook)
plt.title('OOK Modulation')
plt.ylim(-0.5, 1.5)
plt.xlabel('Time')
plt.ylabel('Amplitude')

plt.subplot(412)
plt.plot(t, modulated_bpsk)
plt.title('BPSK Modulation')
plt.ylim(-1.5, 1.5)
plt.xlabel('Time')
plt.ylabel('Amplitude')

plt.subplot(413)
plt.plot(t, modulated_qpsk)
plt.title('QPSK Modulation')
plt.ylim(-1.5, 1.5)
plt.xlabel('Time')
plt.ylabel('Amplitude')

plt.subplot(414)
plt.plot(t, modulated_dbpsk)
plt.title('DBPSK Modulation')
plt.ylim(-1.5, 1.5)
plt.xlabel('Time')
plt.ylabel('Amplitude')

plt.tight_layout()
plt.show()
