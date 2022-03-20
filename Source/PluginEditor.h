/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class NoiseGenAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    NoiseGenAudioProcessorEditor (NoiseGenAudioProcessor&);
    ~NoiseGenAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    juce::Slider gainSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> volumeSliderAttachment;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    NoiseGenAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoiseGenAudioProcessorEditor)
};
