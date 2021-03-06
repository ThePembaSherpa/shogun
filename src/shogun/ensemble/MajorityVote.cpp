/*
 * This software is distributed under BSD 3-clause license (see LICENSE file).
 *
 * Authors: Bjoern Esser, Viktor Gal
 */

#include <shogun/ensemble/MajorityVote.h>
#include <shogun/lib/SGMatrix.h>

using namespace shogun;

CMajorityVote::CMajorityVote()
	: CWeightedMajorityVote()
{

}

CMajorityVote::~CMajorityVote()
{

}

SGVector<float64_t> CMajorityVote::combine(const SGMatrix<float64_t>& ensemble_result) const
{
	m_weights.resize_vector(ensemble_result.num_cols);
	m_weights.set_const(1.0);

	SGVector<float64_t> combined_result = CWeightedMajorityVote::combine(ensemble_result);

	return combined_result;
}

float64_t CMajorityVote::combine(const SGVector<float64_t>& ensemble_result) const
{
	m_weights.resize_vector(ensemble_result.vlen);
	m_weights.set_const(1.0);

	return weighted_combine(ensemble_result);
}
