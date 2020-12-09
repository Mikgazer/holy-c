import null as null

particles_charge_list = [
    {
        "Particle": "Strange",
        "Charm": "Quark",
        "Spin": "1/2",
        "Electric Charge": "-1/3"
    },
    {
        "Particle": "Charm",
        "Charm": "Quark",
        "Spin": "1/2",
        "Electric Charge": "2/3"
    },
    {
        "Particle": "Electron",
        "Charm": "Lepton",
        "Spin": "1/2",
        "Electric Charge": "-1"
    },
    {
        "Particle": "Neutrino",
        "Charm": "Lepton",
        "Spin": "1/2",
        "Electric Charge": "0"
    },
    {
        "Particle": "Photon",
        "Charm": "Boson",
        "Spin": "1",
        "Electric Charge": "0"
    }
]

print("Insert a particle spin and charge: ")
particle_spin = input()
particle_charge = input()

res = [x for x in particles_charge_list if x["Spin"] == particle_spin and x["Electric Charge"] == particle_charge]
if len(res) > 0:
    r = res[0]
    print(r["Charm"], r["Particle"])
else:
    print("Error, no such particle exists!")
