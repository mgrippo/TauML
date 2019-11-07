/*! Definition of a tuple with all event information that is required for the tau analysis.
*/

#pragma once

#include "AnalysisTools/Core/include/SmartTree.h"
#include "TauML/Analysis/include/TauIdResults.h"
#include <Math/VectorUtil.h>

#define TAU_ID(name, pattern, has_raw, wp_list) VAR(uint16_t, name) VAR(Float_t, name##raw)
#define CAND_VAR(type, name) VAR(std::vector<type>, pfCand_##name)
#define ELE_VAR(type, name) VAR(std::vector<type>, ele_##name)
#define MUON_VAR(type, name) VAR(std::vector<type>, muon_##name)

#define VAR2(type, name1, name2) VAR(type, name1) VAR(type, name2)
#define VAR3(type, name1, name2, name3) VAR2(type, name1, name2) VAR(type, name3)
#define VAR4(type, name1, name2, name3, name4) VAR3(type, name1, name2, name3) VAR(type, name4)

#define CAND_VAR2(type, name1, name2) CAND_VAR(type, name1) CAND_VAR(type, name2)
#define CAND_VAR3(type, name1, name2, name3) CAND_VAR2(type, name1, name2) CAND_VAR(type, name3)
#define CAND_VAR4(type, name1, name2, name3, name4) CAND_VAR3(type, name1, name2, name3) CAND_VAR(type, name4)

#define ELE_VAR2(type, name1, name2) ELE_VAR(type, name1) ELE_VAR(type, name2)
#define ELE_VAR3(type, name1, name2, name3) ELE_VAR2(type, name1, name2) ELE_VAR(type, name3)
#define ELE_VAR4(type, name1, name2, name3, name4) ELE_VAR3(type, name1, name2, name3) ELE_VAR(type, name4)

#define MUON_VAR2(type, name1, name2) MUON_VAR(type, name1) MUON_VAR(type, name2)
#define MUON_VAR3(type, name1, name2, name3) MUON_VAR2(type, name1, name2) MUON_VAR(type, name3)
#define MUON_VAR4(type, name1, name2, name3, name4) MUON_VAR3(type, name1, name2, name3) MUON_VAR(type, name4)

#define TAU_DATA() \
    /* Event Variables */ \
    VAR(UInt_t, run) /* run number */ \
    VAR(UInt_t, lumi) /* lumi section */ \
    VAR(ULong64_t, evt) /* event number */ \
    VAR(Int_t, npv) /* number of primary vertices */ \
    VAR(Float_t, rho) /* fixed grid energy density */ \
    VAR(Float_t, genEventWeight) /* gen event weight */ \
    VAR(Float_t, trainingWeight) /* training weight */ \
    VAR(Int_t, sampleType) /* type of the sample (MC, Embedded or Data) */ \
    VAR(Float_t, npu) /* number of in-time pu interactions added to the event */ \
    VAR3(Float_t, pv_x, pv_y, pv_z) /* position of the primary vertex (PV) */ \
    VAR(Float_t, pv_chi2) /* chi^2 of the primary vertex (PV) */ \
    VAR(Float_t, pv_ndof) /* number of degrees of freedom of the primary vertex (PV) */ \
    /* Jet variables */ \
    VAR(Int_t, jet_index) /* index of the jet */ \
    VAR4(Float_t, jet_pt, jet_eta, jet_phi, jet_mass) /* 4-momentum of the jet */ \
    VAR(Float_t, jet_neutralHadronEnergyFraction) /* jet neutral hadron energy fraction
                                                     (relative to uncorrected jet energy) */ \
    VAR(Float_t, jet_neutralEmEnergyFraction) /* jet neutral EM energy fraction
                                                 (relative to uncorrected jet energy) */ \
    VAR(Int_t, jet_nConstituents) /* number of jet constituents */ \
    VAR(Int_t, jet_chargedMultiplicity) /* jet charged multiplicity */ \
    VAR(Int_t, jet_neutralMultiplicity) /* jet neutral multiplicity */ \
    VAR(Int_t, jet_partonFlavour) /* parton-based flavour of the jet */ \
    VAR(Int_t, jet_hadronFlavour) /* hadron-based flavour of the jet */ \
    VAR(Int_t, jet_has_gen_match) /* jet has a matched gen-jet */ \
    VAR4(Float_t, jet_gen_pt, jet_gen_eta, jet_gen_phi, jet_gen_mass) /* 4-momentum of the gen jet */ \
    VAR(Int_t, jet_gen_n_b) /* number of b hadrons clustered inside the jet */ \
    VAR(Int_t, jet_gen_n_c) /* number of c hadrons clustered inside the jet */ \
    /* Basic tau variables */ \
    VAR(Int_t, jetTauMatch) /* match between jet and tau: NoMatch = 0, PF = 1, dR = 2 */ \
    VAR(Int_t, tau_index) /* index of the tau */ \
    VAR4(Float_t, tau_pt, tau_eta, tau_phi, tau_mass) /* 4-momentum of the tau */ \
    VAR(Int_t, tau_charge) /* tau charge */ \
    VAR(Int_t, lepton_gen_match) /* matching with leptons on the generator level (see Htautau Twiki for details):
                                    Electron = 1, Muon = 2, TauElectron = 3, TauMuon = 4, Tau = 5, NoMatch = 6 */\
    VAR(Int_t, lepton_gen_charge) /* charge of the matched gen lepton */ \
    VAR4(Float_t, lepton_gen_pt, lepton_gen_eta, \
                  lepton_gen_phi, lepton_gen_mass) /* 4-momentum of the matched gen lepton */ \
    VAR(std::vector<Int_t>, lepton_gen_vis_pdg) /* PDG of the matched lepton */ \
    VAR4(std::vector<Float_t>, lepton_gen_vis_pt, lepton_gen_vis_eta, \
                               lepton_gen_vis_phi, lepton_gen_vis_mass) /* 4-momenta of the visible products
                                                                           of the matched gen lepton */ \
    VAR(Int_t, qcd_gen_match) /* matching with QCD particles on the generator level:
                                 NoMatch = 0, Down = 1, Up = 2, Strange = 3, Charm = 4, Bottom = 5, Top = 6,
                                 Gluon = 21 */ \
    VAR(Int_t, qcd_gen_charge) /* charge of the matched gen QCD particle */ \
    VAR4(Float_t, qcd_gen_pt, qcd_gen_eta, qcd_gen_phi, qcd_gen_mass) /* 4-momentum of the matched gen QCD particle */ \
    /* Tau ID variables */ \
    VAR(Int_t, tau_decayMode) /* tau decay mode */ \
    VAR(Int_t, tau_decayModeFinding) /* tau passed the old decay mode finding requirements */ \
    VAR(Int_t, tau_decayModeFindingNewDMs) /* tau passed the new decay mode finding requirements */ \
    VAR(Float_t, chargedIsoPtSum) /* sum of the transverse momentums of charged pf candidates inside
                                     the tau isolation cone with dR < 0.5 */ \
    VAR(Float_t, chargedIsoPtSumdR03) /* sum of the transverse momentums of charged pf candidates inside
                                         the tau isolation cone with dR < 0.3 */ \
    VAR(Float_t, footprintCorrection) /* tau footprint correction inside the tau isolation cone with dR < 0.5 */ \
    VAR(Float_t, footprintCorrectiondR03) /* tau footprint correction inside the tau isolation cone with dR < 0.3 */ \
    VAR(Float_t, neutralIsoPtSum) /* sum of the transverse momentums of neutral pf candidates inside
                                     the tau isolation cone with dR < 0.5 */ \
    VAR(Float_t, neutralIsoPtSumWeight) /* weighted sum of the transverse momentums of neutral pf candidates inside
                                           the tau isolation cone with dR < 0.5 */ \
    VAR(Float_t, neutralIsoPtSumWeightdR03) /* weighted sum of the transverse momentums of neutral pf candidates inside
                                               the tau isolation cone with dR < 0.3 */ \
    VAR(Float_t, neutralIsoPtSumdR03) /* sum of the transverse momentums of neutral pf candidates inside
                                         the tau isolation cone with dR < 0.3 */ \
    VAR(Float_t, photonPtSumOutsideSignalCone) /* sum of the transverse momentums of photons
                                                  inside the tau isolation cone with dR < 0.5 */ \
    VAR(Float_t, photonPtSumOutsideSignalConedR03) /* sum of the transverse momentums of photons inside
                                                      the tau isolation cone with dR < 0.3 */ \
    VAR(Float_t, puCorrPtSum) /* pile-up correction for the sum of the transverse momentums */ \
    TAU_IDS() \
    /* Tau transverse impact paramters.
       See cmssw/RecoTauTag/RecoTau/plugins/PFTauTransverseImpactParameters.cc for details */ \
    /* VAR3(Float_t, tau_dxy_pca_x, tau_dxy_pca_y, tau_dxy_pca_z) The point of closest approach (PCA) of the leadPFChargedHadrCand to the primary vertex */ \
    VAR(Float_t, tau_dxy) /* tau signed transverse impact parameter wrt to the primary vertex */ \
    VAR(Float_t, tau_dxy_error) /* uncertainty of the transverse impact parameter measurement */ \
    VAR(Float_t, tau_ip3d) /* tau signed 3D impact parameter wrt to the primary vertex */ \
    VAR(Float_t, tau_ip3d_error) /* uncertainty of the 3D impact parameter measurement */ \
    VAR(Float_t, tau_dz) /* tau dz of the leadChargedHadrCand wrt to the primary vertex */ \
    VAR(Float_t, tau_dz_error) /* uncertainty of the tau dz measurement */ \
    VAR(Int_t, tau_hasSecondaryVertex) /* tau has the secondary vertex */ \
    VAR3(Float_t, tau_sv_x, tau_sv_y, tau_sv_z) /* position of the secondary vertex */ \
    VAR3(Float_t, tau_flightLength_x, tau_flightLength_y, tau_flightLength_z) /* flight length of the tau */ \
    VAR(Float_t, tau_flightLength_sig) /* significance of the flight length measurement */ \
    /* Extended tau variables */ \
    VAR(Float_t, tau_pt_weighted_deta_strip) /* sum of pt weighted values of deta relative to tau candidate
                                                for all pf photon candidates, which are associated to signal */ \
    VAR(Float_t, tau_pt_weighted_dphi_strip) /* sum of pt weighted values of dphi relative to tau candidate
                                                for all pf photon candidates, which are associated to signal */ \
    VAR(Float_t, tau_pt_weighted_dr_signal) /* sum of pt weighted values of dr relative to tau candidate
                                               for all pf photon candidates, which are associated to signal */ \
    VAR(Float_t, tau_pt_weighted_dr_iso) /* sum of pt weighted values of dr relative to tau candidate
                                            for all pf photon candidates, which are inside an isolation cone
                                            but not associated to signal */ \
    VAR(Float_t, tau_leadingTrackNormChi2) /* normalized chi2 of leading track */ \
    VAR(Float_t, tau_e_ratio) /* ratio of energy in ECAL over sum of energy in ECAL and HCAL */ \
    VAR(Float_t, tau_gj_angle_diff) /* Gottfried-Jackson angle difference
                                       (defined olny when the secondary vertex is reconstructed) */ \
    VAR(Int_t, tau_n_photons) /* total number of pf photon candidates with pT>500 MeV,
                                 which are associated to signal */ \
    VAR(Float_t, tau_emFraction) /* tau->emFraction_MVA */ \
    VAR(Int_t, tau_inside_ecal_crack) /* tau is inside the ECAL crack (1.46 < |eta| < 1.558) */ \
    VAR(Float_t, leadChargedCand_etaAtEcalEntrance) /* eta at ECAL entrance of the leadChargedCand */ \
    /* PF candidates */ \
    CAND_VAR(Int_t, jetDaughter) /* PF candidate is a jet daughter */ \
    CAND_VAR(Int_t, tauSignal) /* PF candidate is a part of the tau signal */ \
    CAND_VAR(Int_t, leadChargedHadrCand) /* PF candidate is the leadChargedHadrCand */ \
    CAND_VAR(Int_t, tauIso) /* PF candidate is a parto of the tau isolation */ \
    CAND_VAR4(Float_t, pt, eta, phi, mass) /* 4-momentum of the PF candidate */ \
    CAND_VAR(Int_t, pvAssociationQuality) /* information about how the association to the PV is obtained:
                                             NotReconstructedPrimary = 0, OtherDeltaZ = 1, CompatibilityBTag = 4,
                                             CompatibilityDz = 5, UsedInFitLoose = 6, UsedInFitTight = 7 */ \
    CAND_VAR(Int_t, fromPV) /* the association to PV=ipv. >=PVLoose corresponds to JME definition,
                               >=PVTight to isolation definition:
                               NoPV = 0, PVLoose = 1, PVTight = 2, PVUsedInFit = 3 */ \
    CAND_VAR(Float_t, puppiWeight) /* weight from full PUPPI */ \
    CAND_VAR(Float_t, puppiWeightNoLep) /* weight from PUPPI removing leptons */ \
    CAND_VAR(Int_t, pdgId) /* PDG identifier */ \
    CAND_VAR(Int_t, charge) /* electric charge */ \
    CAND_VAR(Int_t, lostInnerHits) /* enumerator specifying the number of lost inner hits:
                                      validHitInFirstPixelBarrelLayer = -1, noLostInnerHits = 0 (it could still not
                                      have a hit in the first layer, e.g. if it crosses an inactive sensor),
                                      oneLostInnerHit = 1, moreLostInnerHits = 2 */ \
    CAND_VAR(Int_t, numberOfPixelHits) /* number of valid pixel hits */ \
    CAND_VAR3(Float_t, vertex_x, vertex_y, vertex_z) /* position of the vertex to which the candidate is associated */ \
    CAND_VAR(Int_t, hasTrackDetails) /* has track details */ \
    CAND_VAR(Float_t, dxy) /* signed transverse impact parameter wrt to the primary vertex */ \
    CAND_VAR(Float_t, dxy_error) /* uncertainty of the transverse impact parameter measurement */ \
    CAND_VAR(Float_t, dz) /* dz wrt to the primary vertex */ \
    CAND_VAR(Float_t, dz_error) /* uncertainty of the dz measurement */ \
    CAND_VAR(Float_t, track_chi2) /* chi^2 of the pseudo track made with the candidate kinematics */ \
    CAND_VAR(Float_t, track_ndof) /* number of degrees of freedom of the pseudo track
                                     made with the candidate kinematics */ \
    CAND_VAR(Float_t, hcalFraction) /* fraction of ECAL and HCAL for HF and neutral hadrons
                                       and isolated charged hadrons */ \
    CAND_VAR(Float_t, rawCaloFraction) /* raw ECAL+HCAL energy over candidate energy for isolated charged hadrons */ \
    /* PAT electrons + pfCand ele */ \
    ELE_VAR4(Float_t, pt, eta, phi, mass) /* 4-momentum of the electron */ \
    ELE_VAR(Float_t, cc_ele_energy) /* energy of the first calo cluster in the electron super cluster */ \
    ELE_VAR(Float_t, cc_gamma_energy) /* sum of the energies of additional calo clusters
                                         in the electron super cluster */ \
    ELE_VAR(Int_t, cc_n_gamma) /* number of additional calo clusters in the electron super cluster */ \
    CAND_VAR(Float_t, ele_trackMomentumAtVtx) /* module of the track momentum at the PCA to the beam spot */ \
    CAND_VAR(Float_t, ele_trackMomentumAtCalo) /* module of the track momentum extrapolated at the supercluster position
                                             from the innermost track state */ \
    CAND_VAR(Float_t, ele_trackMomentumOut) /* module of the track momentum extrapolated at the seed cluster position
                                          from the outermost track state */ \
    CAND_VAR(Float_t, ele_trackMomentumAtEleClus) /* module of the track momentum extrapolated at the ele cluster position
                                                from the outermost track state */ \
    CAND_VAR(Float_t, ele_trackMomentumAtVtxWithConstraint) /* module of the track momentum at the PCA to the beam spot
                                                          using bs constraint */ \
    CAND_VAR(Float_t, ele_ecalEnergy) /*  corrected ECAL energy */ \
    CAND_VAR(Float_t, ele_ecalEnergy_error) /* uncertanty of the ECAL energy measurement */ \
    CAND_VAR(Float_t, ele_eSuperClusterOverP) /* supercluster energy / track momentum at the PCA to the beam spot */ \
    CAND_VAR(Float_t, ele_eSeedClusterOverP) /* seed cluster energy / track momentum at the PCA to the beam spot */ \
    CAND_VAR(Float_t, ele_eSeedClusterOverPout) /* seed cluster energy / track momentum at calo extrapolated
                                              from the outermost track state */ \
    CAND_VAR(Float_t, ele_eEleClusterOverPout) /* electron cluster energy / track momentum at calo extrapolated
                                             from the outermost track state */ \
    CAND_VAR(Float_t, ele_deltaEtaSuperClusterTrackAtVtx) /* supercluster eta - track eta position at calo extrapolated
                                                        from innermost track state */ \
    CAND_VAR(Float_t, ele_deltaEtaSeedClusterTrackAtCalo) /* seed cluster eta - track eta position at calo extrapolated
                                                        from the outermost track state */ \
    CAND_VAR(Float_t, ele_deltaEtaEleClusterTrackAtCalo) /* electron cluster eta - track eta position at calo extrapolated
                                                       from the outermost state */ \
    CAND_VAR(Float_t, ele_deltaPhiEleClusterTrackAtCalo) /* electron cluster phi - track phi position at calo extrapolated
                                                       from the outermost track state */ \
    CAND_VAR(Float_t, ele_deltaPhiSuperClusterTrackAtVtx) /* supercluster phi - track phi position at calo extrapolated
                                                        from the innermost track state */ \
    CAND_VAR(Float_t, ele_deltaPhiSeedClusterTrackAtCalo) /* seed cluster phi - track phi position at calo extrapolated
                                                        from the outermost track state */ \
    CAND_VAR(Int_t, ele_mvaInput_earlyBrem) /* early bremsstrahlung is detected:
                                                              unknown = -2, could not be evaluated = -1,
                                                              wrong = 0, true = 1 */ \
    CAND_VAR(Int_t, ele_mvaInput_lateBrem) /* late bremsstrahlung is detected:
                                                            unknown = -2, could not be evaluated = -1,
                                                            wrong = 0, true = 1 */ \
    CAND_VAR(Float_t, ele_mvaInput_sigmaEtaEta) /* Sigma-eta-eta with the PF cluster */ \
    CAND_VAR(Float_t, ele_mvaInput_hadEnergy) /* Associated PF Had Cluster energy */ \
    CAND_VAR(Float_t, ele_mvaInput_deltaEta) /* PF-cluster GSF track delta-eta */ \
    ELE_VAR(Float_t, gsfTrack_normalizedChi2) /* chi^2 divided by number of degrees of freedom of the GSF track */ \
    ELE_VAR(Int_t, gsfTrack_numberOfValidHits) /* number of valid hits on the GSF track */ \
    ELE_VAR(Float_t, gsfTrack_pt) /* pt of the GSF track */ \
    ELE_VAR(Float_t, gsfTrack_pt_error) /* uncertainty of the pt measurement of the GSF track */ \
    CAND_VAR(Float_t, ele_closestCtfTrack_normalizedChi2) /* chi^2 divided by number of degrees of freedom
                                                        of the closest CTF track */ \
    CAND_VAR(Int_t, ele_closestCtfTrack_numberOfValidHits) /* number of valid hits on the closest CTF track */ \
    /* PAT muons */ \
    MUON_VAR4(Float_t, pt, eta, phi, mass) /* 4-momentum of the muon */ \
    MUON_VAR(Float_t, dxy) /* signed transverse impact parameter of the inner track wrt to the primary vertex */ \
    MUON_VAR(Float_t, dxy_error) /* uncertainty of the transverse impact parameter measurement */ \
    MUON_VAR(Float_t, normalizedChi2) /* chi^2 divided by number of degrees of freedom of the global track */ \
    MUON_VAR(Int_t, numberOfValidHits) /* number of valid hits on the global track */ \
    MUON_VAR(Float_t, segmentCompatibility) /* segment compatibility for a track with matched muon info */ \
    MUON_VAR(Float_t, caloCompatibility) /* relative likelihood based on ECAL, HCAL, HO energy defined as
                                            L_muon / (L_muon + L_not_muon) */ \
    MUON_VAR(Float_t, pfEcalEnergy) /* PF based energy deposition in the ECAL */ \
    MUON_VAR4(Int_t, n_matches_DT_1, n_matches_DT_2, n_matches_DT_3, \
                     n_matches_DT_4) /* number of segment matches for the DT subdetector stations */ \
    MUON_VAR4(Int_t, n_matches_CSC_1, n_matches_CSC_2, n_matches_CSC_3, \
                     n_matches_CSC_4) /* number of segment matches for the CSC subdetector stations */ \
    MUON_VAR4(Int_t, n_matches_RPC_1, n_matches_RPC_2, n_matches_RPC_3, \
                     n_matches_RPC_4) /* number of segment matches for the RPC subdetector stations */ \
    MUON_VAR4(Int_t, n_hits_DT_1, n_hits_DT_2, n_hits_DT_3, \
                     n_hits_DT_4) /* number of valid and bad hits for the DT subdetector stations */ \
    MUON_VAR4(Int_t, n_hits_CSC_1, n_hits_CSC_2, n_hits_CSC_3, \
                     n_hits_CSC_4) /* number of valid and bad hits for the CSC subdetector stations */ \
    MUON_VAR4(Int_t, n_hits_RPC_1, n_hits_RPC_2, n_hits_RPC_3, \
                     n_hits_RPC_4) /* number of valid and bad hits for the RPC subdetector stations */ \
    /**/

#define VAR(type, name) DECLARE_BRANCH_VARIABLE(type, name)
DECLARE_TREE(tau_tuple, Tau, TauTuple, TAU_DATA, "taus")
#undef VAR

#define VAR(type, name) ADD_DATA_TREE_BRANCH(name)
INITIALIZE_TREE(tau_tuple, TauTuple, TAU_DATA)
#undef VAR
#undef VAR2
#undef VAR3
#undef VAR4
#undef TAU_DATA
#undef CAND_VAR
#undef CAND_VAR2
#undef CAND_VAR3
#undef CAND_VAR4
#undef ELE_VAR
#undef ELE_VAR2
#undef ELE_VAR3
#undef ELE_VAR4
#undef MUON_VAR
#undef MUON_VAR2
#undef MUON_VAR3
#undef MUON_VAR4
#undef TAU_ID

namespace tau_tuple {

template<typename T>
constexpr T DefaultFillValue() { return std::numeric_limits<T>::lowest(); }
template<>
constexpr float DefaultFillValue<float>() { return -999.; }
template<>
constexpr int DefaultFillValue<int>() { return -999; }

enum class ComponenetType { Gamma = 0, ChargedHadronCandidate = 1, NeutralHadronCandidate = 2};

struct TauTupleEntryId {
    UInt_t run;
    UInt_t lumi;
    ULong64_t evt;
    Int_t jet_index, tau_index;

    TauTupleEntryId() {}
    explicit TauTupleEntryId(const Tau& tau) :
        run(tau.run), lumi(tau.lumi), evt(tau.evt), jet_index(tau.jet_index), tau_index(tau.tau_index) {}

    bool operator<(const TauTupleEntryId& other) const
    {
        if(run != other.run) return run < other.run;
        if(lumi != other.lumi) return lumi < other.lumi;
        if(evt != other.evt) return evt < other.evt;
        if(jet_index != other.jet_index) return jet_index < other.jet_index;
        return tau_index < other.tau_index;
    }
};

} // namespace tau_tuple
