/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class NoiseGenAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    NoiseGenAudioProcessor();
    ~NoiseGenAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    juce::AudioProcessorValueTreeState apvts;

private:
    //==============================================================================
    juce::Random random;
    
    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
        
    // gain related variables and pointers
    float previousGain; // [1]
    float level = 0.0f;
    
    float minDb = juce::Decibels::gainToDecibels(0.0f);
    float maxDb = juce::Decibels::gainToDecibels(1.0f);
    float dbAtMidPoint = -6.0f;
    
    std::atomic<float>* gainParameter = nullptr;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoiseGenAudioProcessor)
};
