/*
 *  Gazebo - Outdoor Multi-Robot Simulator
 *  Copyright (C) 2003  
 *     Nate Koenig & Andrew Howard
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
/* Desc: Box geometry
 * Author: Nate Keonig, Andrew Howard
 * Date: 8 May 2003
 * SVN: $Id: BoxGeom.hh 7039 2008-09-24 18:06:29Z natepak $
 *
 * Modified by: Eurico Pedrosa <efp@ua.p>
 * Date: 10 Fev 2010
 *
 * Modification Notes
 *
 *  The modifications presented by me, have the purpose of
 *  removing the 'rendering' and 'gui' modules from the code base.
 *  The reasons behind this decision are simple, allow gazebo to run
 *  on computers with less gpu capabilities and lessen the the coupling
 *  between simulation and visualization.
 *
 */

#ifndef BOXSHAPE_HH
#define BOXSHAPE_HH

#include "Param.hh"
#include "Shape.hh"

namespace gazebo
{

  /// \addtogroup gazebo_physics_geom
  /// \{
  /** \defgroup gazebo_box_geom Box Geom
    \brief Box geom

    \par Attributes
    The following attributes are supported.

    \htmlinclude default_geom_attr_include.html

    - size (float tuple, meters)
      - Size of the box
      - Default: 0 0 0

    \par Example
    \verbatim
    <geom:box name="geom_name">
      <xyz>1 2 3</xyz>
      <rpy>0 0 30</rpy>
      <size>0.1 0.2 0.3</size>
      <mass>0.5</mass>
      <laserFiducialId>1</laserFiducialId>
      <laserRetro>0.5</laserRetro>

      <visual>
        <size>0.1 0.2 0.3</size>
        <mesh>default</mesh>
        <material>Gazebo/Red</material>
      </visual>
    </geom:box>
    \endverbatim
    */
  /// \}
  /// \addtogroup gazebo_box_geom 
  /// \{

  /// \brief Box geom
  class BoxShape : public Shape
  {
    /// \brief Constructor
    public: BoxShape(Geom *parent);

    /// \brief Destructor
    public: virtual ~BoxShape();

    /// \brief Load the box
    public: virtual void Load(XMLConfigNode *node);

    /// \brief Save child parameters
    public: virtual void Save(std::string &prefix, std::ostream &stream);

    /// \brief Set the size of the box
    public: virtual void SetSize( const Vector3 &size );
    
    /// \brief Get the size of the box
    public: virtual const Vector3 GetSize( );

    private: ParamT<Vector3> *sizeP;
  };

  /// \}

}
#endif
